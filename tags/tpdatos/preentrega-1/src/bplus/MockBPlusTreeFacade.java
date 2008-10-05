package bplus;

import api.bo.BPlusTree.BPlusTreeBo;
import app.bo.bplus.BPlusTreeBoTest;
import exceptions.DataAccessException;

public class MockBPlusTreeFacade extends BPlusTreeFacade {

	public MockBPlusTreeFacade() throws DataAccessException {
		super();
	}

	
	protected BPlusTreeBo createBo() throws DataAccessException{
		return new BPlusTreeBoTest();
	}
	
}
