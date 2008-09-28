package app.bo;

import java.util.Iterator;

import documents.keys.DocumentIndexKey;

import bplus.BPlusTreeFacade;
import bplus.MockBPlusTreeFacade;
import bplus.exceptions.KeyNotFoundException;

import exceptions.BusinessException;
import exceptions.DataAccessException;
import api.bo.Index;

public class IndexImp implements Index {

	private BPlusTreeFacade btree;
	
	public IndexImp() throws BusinessException {
		try {
			this.btree = this.createBTree();
		} catch (DataAccessException e) {
			throw new BusinessException("Error creando el btree",e);
		}
	}
	
	public Iterator<Integer> getDocuments(String word) throws BusinessException {
		// TODO Auto-generated method stub
		return null;
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
		// TODO implementar la rutina para insertar el documento
		// de id docId en el bloque docBlockId del LinkedBlock
		
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
				// TODO Auto-generated catch block
				throw new BusinessException("Error insertando elemento en el btree",e1);
			}
			
			
		} catch (DataAccessException e) {
			// TODO Auto-generated catch block
			throw new BusinessException("Error leyendo elemento del btree",e);		
		}

		return doc;
	}
	
	protected DocumentIndexKey createBlock() {
		// TODO crear un bloque en el LinkedBlocks
		return null;
	}
	protected BPlusTreeFacade createBTree() throws DataAccessException {
		return new MockBPlusTreeFacade();
	}

}
