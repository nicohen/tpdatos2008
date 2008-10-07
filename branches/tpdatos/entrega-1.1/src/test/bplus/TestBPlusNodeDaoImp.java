package test.bplus;

import utils.Constants;
import api.dao.BPlusTree.BPlusNodeDao;
import app.dao.bplus.BPlusNodeDaoImp;
import exceptions.DataAccessException;

public class TestBPlusNodeDaoImp extends TestBPlusNodeDao {

	public TestBPlusNodeDaoImp() throws DataAccessException {
		super();
		// TODO Auto-generated constructor stub
	}

	@Override
	protected BPlusNodeDao createTestObject() throws DataAccessException {
		// TODO Asegurarse de eliminar prueba.bin antes
		return new BPlusNodeDaoImp(Constants.BPLUS_TEST_FILE_PATH,Constants.BPLUS_FILE_SIZE);
	}

}
