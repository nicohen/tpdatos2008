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

/*	public void insertNode(BPlusNode node) {
		//TODO - Implementar insertNode
	}
	
	public void getNode(Integer id) {
		//TODO - Implementar getNode
	}*/
	
	private BPlusTreeBo bo;
	
	public BPlusTreeFacade() throws DataAccessException {
		bo = this.createBo();
	}
	
	public DocumentIndexKey getElement( String key ) throws KeyNotFoundException, DataAccessException {
		// TODO
		return new DocumentIndexKey(  
				bo.getElement(new BPlusElementKey(key) ).getValue()
			);
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
			throw new BusinessException("",e);
		}
	}
	
	protected BPlusTreeBo createBo() throws DataAccessException{
		return new BPlusTreeBoImp(Constants.BPLUS_FILE_PATH,Constants.BPLUS_FILE_SIZE);
	}
}
