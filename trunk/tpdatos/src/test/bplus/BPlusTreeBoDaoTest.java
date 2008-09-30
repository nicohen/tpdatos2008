package test.bplus;

import app.bo.bplus.AbstractBPlusTreeBo;
import app.dao.bplus.BPlusNodeDaoTest;
import exceptions.DataAccessException;

public class BPlusTreeBoDaoTest extends AbstractBPlusTreeBo {

	public BPlusTreeBoDaoTest() throws DataAccessException {
		super();
		setDao(new BPlusNodeDaoTest());
	}
}
