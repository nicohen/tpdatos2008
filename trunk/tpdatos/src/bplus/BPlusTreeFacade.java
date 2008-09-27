package bplus;

import api.bo.BPlusTree.BPlusTreeBo;
import app.bo.bplus.BPlusTreeBoImp;
import bplus.elements.BPlusLeafElement;
import bplus.exceptions.KeyNotFoundException;
import bplus.keys.BPlusElementKey;
import documents.keys.DocumentIndexKey;
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
		bo.insertElement( new BPlusLeafElement(new BPlusElementKey(key), value.getValue() ) );
	}
	
	private BPlusTreeBo createBo() throws DataAccessException{
		return new BPlusTreeBoImp("bplus.dat",128);
	}
}