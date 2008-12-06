package app.bo.bplus;

import app.dao.bplus.BPlusNodeDaoImp;
import exceptions.DataAccessException;

public class BPlusTreeBoImp extends AbstractBPlusTreeBo {

	public BPlusTreeBoImp( String filename, int nodeSize ) throws DataAccessException {
		setDao(new BPlusNodeDaoImp(filename,nodeSize));
	}
	
}
