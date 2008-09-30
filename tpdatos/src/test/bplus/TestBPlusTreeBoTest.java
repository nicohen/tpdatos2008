package test.bplus;

import api.bo.BPlusTree.BPlusTreeBo;
import app.bo.bplus.BPlusTreeBoTest;
import exceptions.DataAccessException;

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
