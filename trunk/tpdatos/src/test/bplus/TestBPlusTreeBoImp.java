package test.bplus;

import exceptions.DataAccessException;
import api.bo.BPlusTree.BPlusTreeBo;
import app.bo.bplus.BPlusTreeBoImp;

public class TestBPlusTreeBoImp extends TestBPlusTreeBo {

	@Override
	protected BPlusTreeBo createTestObject() throws DataAccessException {
		// TODO Auto-generated method stub
		return new BPlusTreeBoImp() ;
	}

}
