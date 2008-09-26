package test.bplus;

import api.dao.BPlusTree.BPlusNodeDao;
import app.dao.bplus.BPlusNodeDaoTest;

public class TestBPlusNodeDaoTest extends TestBPlusNodeDao {

	@Override
	protected BPlusNodeDao createTestObject() {
		// TODO Auto-generated method stub
		return new BPlusNodeDaoTest();
	}

}
