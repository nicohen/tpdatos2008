package test.bplus;

import exceptions.DataAccessException;
import api.dao.BPlusTree.BPlusNodeDao;
import app.dao.bplus.BPlusNodeDaoTest;

public class TestBPlusNodeDaoTest extends TestBPlusNodeDao {

	public TestBPlusNodeDaoTest() throws DataAccessException {
		super();
		// TODO Auto-generated constructor stub
	}

	@Override
	protected BPlusNodeDao createTestObject() throws DataAccessException {
		// TODO Auto-generated method stub
		return new BPlusNodeDaoTest();
	}

}
