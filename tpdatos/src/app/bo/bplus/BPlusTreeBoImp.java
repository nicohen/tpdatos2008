package app.bo.bplus;

import api.dao.BPlusTree.BPlusNodeDao;
import app.dao.bplus.BPlusNodeDaoImp;
import bplus.keys.BPlusNodeKey;
import bplus.nodes.BPlusLeafNode;
import exceptions.DataAccessException;

public class BPlusTreeBoImp extends AbstractBPlusTreeBo {

	private String filename;
	
	public BPlusTreeBoImp( String filename, int nodeSize ) throws DataAccessException {
		super();
		this.filename= filename;
		// TODO Auto-generated constructor stub
		this.nodeDao= new BPlusNodeDaoImp(filename,nodeSize);
		if (this.nodeDao.getSize()==0){
			this.root= new BPlusLeafNode();
			nodeDao.insertNode(root);
		}else{
			nodeDao.getNode(new BPlusNodeKey(0));
		}
	}

	public BPlusTreeBoImp( ) throws DataAccessException {
		super();
		// TODO Auto-generated constructor stub
		this.filename = "bplus.dat";
	}

	@Override
	protected BPlusNodeDao createDao() throws DataAccessException {
		return null;
	}

		
}
