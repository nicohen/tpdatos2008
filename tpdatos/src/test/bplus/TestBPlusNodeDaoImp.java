package test.bplus;

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
		return new BPlusNodeDaoImp("bplus-test.dat",128);
	}

}
