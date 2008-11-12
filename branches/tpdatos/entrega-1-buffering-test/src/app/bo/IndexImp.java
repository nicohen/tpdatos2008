package app.bo;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import linkedblocks.VariableLinkedBlocksManager;
import linkedblocks.keys.DocumentIndexKey;
import linkedblocks.utils.KeyCodificationUtils;
import api.Index;
import app.po.persistors.LinkedBlockByteArrayPersistor;
import bplus.BPlusTreeFacade;
import bplus.exceptions.KeyNotFoundException;
import exceptions.BusinessException;
import exceptions.DataAccessException;

public class IndexImp implements Index {

	private BPlusTreeFacade btree;
	private VariableLinkedBlocksManager manager;

	public IndexImp(String path,int blockSize) throws BusinessException {
		try {
			LinkedBlockByteArrayPersistor persistor=new LinkedBlockByteArrayPersistor(blockSize);
			manager=new VariableLinkedBlocksManager(path, persistor);
			this.btree = this.createBTree();
		} catch (DataAccessException e) {
			throw new BusinessException("Error creando el btree",e);
		}
	}

	private List<Integer> getDocuments(DocumentIndexKey docBlockId) throws BusinessException {
		ArrayList<Integer> listaRet=new ArrayList<Integer>();

		Iterator<byte[]> it=manager.get(docBlockId.getValue());
		
		Integer lastdocid = 0;
			
		while(it.hasNext()){
			lastdocid += ( KeyCodificationUtils.gammaDecode(it.next()));
			listaRet.add(lastdocid);
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
		
		Iterator<Integer> it = this.getDocuments(docBlockId).iterator();
		
		Integer lastDocument = 0;
		while (it.hasNext() ) {
			lastDocument = it.next();
		}

		Integer diferencia = docId - lastDocument;

		if ( diferencia < 0) {
			throw new BusinessException("docid - lastDocument < 0");
		} else {
			// no importa si la diferencia es cero, se puede almacenar, haciendo una pequeña correccion
			manager.add(KeyCodificationUtils.gammaEncode(diferencia), docBlockId.getValue());
		}
	
	}

	private DocumentIndexKey obtainDocIndex( String word ) throws BusinessException {
		DocumentIndexKey doc;
		try {
			doc = btree.getElement(word);
		} catch (KeyNotFoundException e) {
			
			// podria ser el caso de que no existise la clave
			// en ese caso debe insertarse en el arbol
			doc = createBlock();
			
			try {
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
	protected DocumentIndexKey createBlock() {
		// crea un bloque en el LinkedBlocks
		DocumentIndexKey newBlockId=new DocumentIndexKey(manager.addBlock());
		return newBlockId;
	}
	protected BPlusTreeFacade createBTree() throws DataAccessException {
		return new BPlusTreeFacade();
	}

	public void dump() throws BusinessException {
		btree.dump();
	}
}