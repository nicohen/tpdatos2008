package test.bplus;

import exceptions.DataAccessException;
import api.dao.BPlusTree.BPlusNodeDao;
import app.bo.bplus.AbstractBPlusTreeBo;
import app.dao.bplus.BPlusNodeDaoTest;

public class BPlusTreeBoDaoTest extends AbstractBPlusTreeBo {

	public BPlusTreeBoDaoTest() throws DataAccessException {
		super();
	}

	@Override
	protected BPlusNodeDao createDao() throws DataAccessException {
		return new BPlusNodeDaoTest();
	}

}
