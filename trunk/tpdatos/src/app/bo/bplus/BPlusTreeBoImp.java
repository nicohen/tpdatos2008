package app.bo.bplus;

import api.dao.BPlusTree.BPlusNodeDao;
import app.dao.bplus.BPlusNodeDaoImp;
import bplus.keys.BPlusNodeKey;
import bplus.nodes.BPlusLeafNode;
import exceptions.DataAccessException;

public class BPlusTreeBoImp extends AbstractBPlusTreeBo {

	private String filename;
	private int nodeSize;
	
	public BPlusTreeBoImp( String filename, int nodeSize ) throws DataAccessException {
		this.filename= filename;
		this.nodeSize = nodeSize;
	}

/*	public BPlusTreeBoImp( ) throws DataAccessException {
		super();
		// TODO Auto-generated constructor stub
		this.filename = "bplus.dat";
	}*/

	@Override
	protected BPlusNodeDao createDao() throws DataAccessException {
		 return new BPlusNodeDaoImp(filename,nodeSize);
	}

		
}
