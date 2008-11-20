package bplus;

import utils.Constants;
import api.bo.BPlusTree.BPlusTreeBo;
import app.bo.bplus.BPlusTreeBoTest;
import exceptions.DataAccessException;

public class MockBPlusTreeFacade extends BPlusTreeFacade {

	public MockBPlusTreeFacade() throws DataAccessException {
		super(Constants.BPLUS_FILE_SIZE);
	}

	
	protected BPlusTreeBo createBo() throws DataAccessException{
		return new BPlusTreeBoTest();
	}
	
}
