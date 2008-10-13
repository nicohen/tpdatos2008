package app.bo;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import linkedblocks.LinkedBlocksManagerB;
import linkedblocks.codification.GammaDistancesBlock;
import linkedblocks.keys.DocumentIndexKey;
import api.Index;
import app.po.persistors.GammaDistancesBlockPersistor;
import app.po.persistors.LinkedBlockPersistor;
import bplus.BPlusTreeFacade;
import bplus.exceptions.KeyNotFoundException;
import exceptions.BusinessException;
import exceptions.DataAccessException;
import exceptions.PersistanceException;

public class IndexImpB implements Index {

	private BPlusTreeFacade btree;
	private LinkedBlocksManagerB<GammaDistancesBlock> manager;
	private int blockSize;

	public IndexImpB(String path,int blockSize) throws BusinessException {
		try {
			
			GammaDistancesBlockPersistor subpersistor = new GammaDistancesBlockPersistor(blockSize-4);
			LinkedBlockPersistor<GammaDistancesBlock> persistor=new LinkedBlockPersistor<GammaDistancesBlock>(subpersistor);
			manager=new LinkedBlocksManagerB<GammaDistancesBlock>(path, persistor);
			this.blockSize = blockSize;
			this.btree = this.createBTree();
		} catch (DataAccessException e) {
			throw new BusinessException("Error creando el btree",e);
		}
	}

	private List<Integer> getDocuments(DocumentIndexKey docBlockId) throws BusinessException {
		ArrayList<Integer> listaRet=new ArrayList<Integer>();

		Iterator<GammaDistancesBlock> it=manager.get(docBlockId.getValue());
		
		Integer lastdocid = 0;
			
		while(it.hasNext()){
			
			GammaDistancesBlock gammaBlock = it.next();
			
			Iterator<Integer> gammaBlockIt = gammaBlock.decodeDistances();

			while (gammaBlockIt.hasNext() ) {
				lastdocid +=gammaBlockIt.next();
				listaRet.add(lastdocid);
			}
		}

		return listaRet;
	}
	public List<Integer> getDocuments(String word) throws BusinessException {
		
		DocumentIndexKey docBlockId;
		docBlockId=this.searchDocIndex(word);
		if (docBlockId.getValue()!=-1){
			return getDocuments(docBlockId);
		}
		return new ArrayList<Integer>();
	}

	public void insertWord(String word, Integer docId)
			throws BusinessException {

		// buscar la palabra en el btree
		DocumentIndexKey docBlockId;

		docBlockId = this.obtainDocIndex(word);
		
		// en este punto, se pudo obtener el indice del documento
		// ( numero de bloque en el index doc), para ese word
		
		this.insertDocument( docBlockId, docId );

	}
	
	private void insertDocument(DocumentIndexKey docBlockId, Integer docId) throws BusinessException {
		
		// Para evitar el problema de leer dos veces el linked block, podria implemenarse
		// un buffer para el linked block
		
		Iterator<GammaDistancesBlock> it=manager.get(docBlockId.getValue());
		
		Integer lastdocid = 0;
		
		GammaDistancesBlock lastGammaBlock = null;
			
		while(it.hasNext()){
			
			GammaDistancesBlock gammaBlock = it.next();
			lastGammaBlock = gammaBlock;
			
			Iterator<Integer> gammaBlockIt = gammaBlock.decodeDistances();

			while (gammaBlockIt.hasNext() ) {
				lastdocid +=gammaBlockIt.next();
			}
		}

		Integer diferencia = docId - lastdocid;

		if ( diferencia < 0) {
			throw new BusinessException("docid - lastDocument < 0");
		} else {
			// no importa si la diferencia es cero, se puede almacenar, haciendo una pequeña correccion
			//manager.add(KeyCodificationUtils.gammaEncode(diferencia), docBlockId.getValue());
			if (lastGammaBlock != null ) {
				try {
					lastGammaBlock.encodeDistance(diferencia);
				} catch (PersistanceException e) {
					lastGammaBlock = new GammaDistancesBlock(blockSize-4);
					try {
						lastGammaBlock.encodeDistance(diferencia);
						manager.add(lastGammaBlock,docBlockId.getValue());
					} catch (PersistanceException e1) {
						
						throw new BusinessException("Codigo gamma demasiado grande",e1);
					}
				}
			}
			
		}
	
	}

	private DocumentIndexKey obtainDocIndex( String word ) throws BusinessException {
		DocumentIndexKey doc;
		try {
			doc = btree.getElement(word);
		} catch (KeyNotFoundException e) {
			
			// podria ser el caso de que no existise la clave
			// en ese caso debe insertarse en el arbol
			try {
				doc = createBlock();
				btree.insertElement(word, doc);
			} catch (DataAccessException e1) {
				throw new BusinessException("Error insertando [WORD: "+word+"] en el btree",e1);
			}
			
			
		} catch (DataAccessException e) {
			throw new BusinessException("Error leyendo documento para el [WORD: "+word+"] del btree",e);		
		}

		return doc;
	}
	private DocumentIndexKey searchDocIndex( String word ) throws BusinessException {
		DocumentIndexKey doc;
		
		try {
			doc = btree.getElement(word);
		} catch (KeyNotFoundException e) {
			
			// podria ser el caso de que no existise la clave
			doc=new DocumentIndexKey(-1);
			
			
		} catch (DataAccessException e) {
			throw new BusinessException("Error leyendo documento para el [WORD: "+word+"] del btree",e);		
		}

		return doc;
	}
	protected DocumentIndexKey createBlock() throws DataAccessException {
		// crea un bloque en el LinkedBlocks
		int index;
		try {
			index = manager.add(new GammaDistancesBlock(blockSize-4));
		} catch (PersistanceException e) {
			// TODO Auto-generated catch block
			throw new DataAccessException("Error al instanciar GammaDistancesBlock",e);
		}
		DocumentIndexKey newBlockId=new DocumentIndexKey(index);
		return newBlockId;
	}
	protected BPlusTreeFacade createBTree() throws DataAccessException {
		return new BPlusTreeFacade();
	}

	public void dump() throws BusinessException {
		btree.dump();
	}
}
