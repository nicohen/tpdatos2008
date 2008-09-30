package test.bplus;

import exceptions.DataAccessException;
import api.bo.BPlusTree.BPlusTreeBo;
import app.bo.bplus.BPlusTreeBoTest;

public class TestBPlusTreeBoTest extends TestBPlusTreeBo {

	public TestBPlusTreeBoTest() throws DataAccessException {
		super();
		// TODO Auto-generated constructor stub
	}

	@Override
	protected BPlusTreeBo createTestObject() {
		// TODO Auto-generated method stub
		return new BPlusTreeBoTest();
	}

}
