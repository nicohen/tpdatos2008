package app.bo;

import java.util.ArrayList;
import java.util.Iterator;

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
	
	public Iterator<Integer> getDocuments(String word) throws BusinessException {
		
		DocumentIndexKey docBlockId;
		ArrayList<Integer> listaRet=new ArrayList<Integer>();
		Iterator<Integer> itRet;
		docBlockId=this.searchDocIndex(word);
		if (docBlockId.getValue()!=-1){
			Iterator<byte[]> it=manager.get(docBlockId.getValue());
			
			while(it.hasNext()){
				listaRet.add(KeyCodificationUtils.gammaDecode(it.next()) - 1);
			}
		}
		itRet=listaRet.iterator();
		return itRet;
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
	
	private void insertDocument(DocumentIndexKey docBlockId, Integer docId) {
		
		manager.add(KeyCodificationUtils.gammaEncode(docId+1), docBlockId.getValue());
	
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
