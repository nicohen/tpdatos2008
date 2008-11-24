package bplus;

import linkedblocks.keys.DocumentIndexKey;
import utils.Constants;
import api.bo.BPlusTree.BPlusTreeBo;
import app.bo.bplus.BPlusTreeBoImp;
import bplus.elements.BPlusLeafElement;
import bplus.exceptions.KeyNotFoundException;
import bplus.keys.BPlusElementKey;
import exceptions.BusinessException;
import exceptions.DataAccessException;

public class BPlusTreeFacade {

	private BPlusTreeBo bo;
	
	public BPlusTreeFacade(String basePath, int nodeSize) throws DataAccessException {
		bo = this.createBo(basePath, nodeSize);
	}
	
	public DocumentIndexKey getElement( String key ) throws KeyNotFoundException, DataAccessException {
		BPlusLeafElement element= bo.getElement(new BPlusElementKey(key) );
		return new DocumentIndexKey(element.getValue());

	}
	
	public void insertElement (String key , DocumentIndexKey value ) throws DataAccessException {
		// TODO: asignar valor al elemento !!!!
		BPlusLeafElement element= new BPlusLeafElement(new BPlusElementKey(key));
		element.setValue(value.getValue());
		bo.insertElement( element);
	}
	
	public void dump() throws BusinessException {
		try {
			bo.dump();
		} catch(DataAccessException e) {
			throw new BusinessException("Error al recorrer el arbol.",e);
		}
	}
	
	protected BPlusTreeBo createBo(String basePath,int nodeSize) throws DataAccessException{
		return new BPlusTreeBoImp(basePath+Constants.BPLUS_FILE_PATH,nodeSize);
	}
}
