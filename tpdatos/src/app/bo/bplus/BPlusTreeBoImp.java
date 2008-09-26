package app.bo.bplus;

import api.dao.BPlusTree.BPlusNodeDao;
import app.dao.bplus.BPlusNodeDaoImp;
import exceptions.DataAccessException;

public class BPlusTreeBoImp extends AbstractBPlusTreeBo {

	private String filename;
	
	public BPlusTreeBoImp( String filename ) throws DataAccessException {
		super();
		// TODO Auto-generated constructor stub
		this.filename = filename;
	}

	public BPlusTreeBoImp( ) throws DataAccessException {
		super();
		// TODO Auto-generated constructor stub
		this.filename = "bplus.dat";
	}

	@Override
	protected BPlusNodeDao createDao() throws DataAccessException {
		// TODO Auto-generated method stub
		return new BPlusNodeDaoImp(filename);
	}

		
}
