package test.bplus;

import api.bo.BPlusTree.BPlusTreeBo;
import exceptions.DataAccessException;

public class TestBPlusTreeBoImpDaoTest extends TestBPlusTreeBo {

	@Override
	protected BPlusTreeBo createTestObject() throws DataAccessException {
		// devuelve un BPlusTreeBo que usa un dao de prueba
		return new BPlusTreeBoDaoTest();
	}

}
