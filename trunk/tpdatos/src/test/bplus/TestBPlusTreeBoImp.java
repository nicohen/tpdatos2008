package test.bplus;

import api.bo.BPlusTree.BPlusTreeBo;
import app.bo.bplus.BPlusTreeBoImp;
import exceptions.DataAccessException;

public class TestBPlusTreeBoImp extends TestBPlusTreeBo {

	public TestBPlusTreeBoImp() throws DataAccessException {
		super();
		// TODO Auto-generated constructor stub
	}

	@Override
	protected BPlusTreeBo createTestObject() throws DataAccessException {
		// TODO Auto-generated method stub
		return new BPlusTreeBoImp("bplus-bo-test.dat",64) ;
	}
	/*
	public void testDump() throws DataAccessException{
		((BPlusTreeBoImp)this.bo).dump();
	}
	*/
}
