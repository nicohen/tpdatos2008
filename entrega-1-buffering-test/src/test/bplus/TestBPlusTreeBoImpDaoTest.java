package test.bplus;

import api.bo.BPlusTree.BPlusTreeBo;
import exceptions.DataAccessException;

public class TestBPlusTreeBoImpDaoTest extends TestBPlusTreeBo {

	public TestBPlusTreeBoImpDaoTest() throws DataAccessException {
		super();
		// TODO Auto-generated constructor stub
	}

	@Override
	protected BPlusTreeBo createTestObject() throws DataAccessException {
		// devuelve un BPlusTreeBo que usa un dao de prueba
		return new BPlusTreeBoDaoTest();
	}

}
