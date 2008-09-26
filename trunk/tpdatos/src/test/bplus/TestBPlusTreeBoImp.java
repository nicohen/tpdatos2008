package test.bplus;

import api.bo.BPlusTree.BPlusTreeBo;
import app.bo.bplus.BPlusTreeBoImp;
import exceptions.DataAccessException;

public class TestBPlusTreeBoImp extends TestBPlusTreeBo {

	@Override
	protected BPlusTreeBo createTestObject() throws DataAccessException {
		// TODO Auto-generated method stub
		return new BPlusTreeBoImp() ;
	}

}
