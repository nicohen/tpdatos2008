package app.bo.bplus;

import app.dao.bplus.BPlusNodeDaoImp;
import exceptions.DataAccessException;

public class BPlusTreeBoImp extends AbstractBPlusTreeBo {

	private String filename;
	private int nodeSize;
	
	public BPlusTreeBoImp( String filename, int nodeSize ) throws DataAccessException {
		this.filename= filename;
		this.nodeSize = nodeSize;
		this.nodeDao = new BPlusNodeDaoImp(filename,nodeSize);
		this.root=nodeDao.getRootNode();
	}		
}
