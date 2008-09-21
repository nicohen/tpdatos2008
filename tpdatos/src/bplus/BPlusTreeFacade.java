package bplus;

import bplus.elements.BPlusLeafElement;
import bplus.exceptions.KeyNotFoundException;
import bplus.keys.BPlusElementKey;
import api.bo.BPlusTree.BPlusTreeBo;
import app.bo.bplus.BPlusTreeBoImp;

public class BPlusTreeFacade {

/*	public void insertNode(BPlusNode node) {
		//TODO - Implementar insertNode
	}
	
	public void getNode(Integer id) {
		//TODO - Implementar getNode
	}*/
	
	private BPlusTreeBo bo = new BPlusTreeBoImp();
	
	public BPlusLeafElement getElement( String key ) throws KeyNotFoundException {
		// TODO
		return bo.getElement(new BPlusElementKey(key) );
	}
	
	public void insertElement (String key , Integer value ) {
		// TODO: asignar valor al elemento !!!!
		bo.insertElement( new BPlusLeafElement(new BPlusElementKey(key) ) );
	}
	
	
}
