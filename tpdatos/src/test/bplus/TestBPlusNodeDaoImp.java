package test.bplus;

import exceptions.DataAccessException;
import api.dao.BPlusTree.BPlusNodeDao;
import app.dao.bplus.BPlusNodeDaoImp;

public class TestBPlusNodeDaoImp extends TestBPlusNodeDao {

	@Override
	protected BPlusNodeDao createTestObject() throws DataAccessException {
		// TODO Asegurarse de eliminar prueba.bin antes
		return new BPlusNodeDaoImp("bplus-test.dat");
	}

}
