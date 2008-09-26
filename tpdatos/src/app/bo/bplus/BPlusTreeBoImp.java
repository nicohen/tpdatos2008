package app.bo.bplus;

import java.util.Iterator;
import java.util.List;

import api.bo.BPlusTree.BPlusTreeBo;
import api.dao.BPlusTree.BPlusNodeDao;
import app.dao.bplus.BPlusNodeDaoImp;
import bplus.elements.BPlusElement;
import bplus.elements.BPlusIndexElement;
import bplus.elements.BPlusLeafElement;
import bplus.exceptions.KeyNotFoundException;
import bplus.exceptions.NodeOverflowException;
import bplus.keys.BPlusElementKey;
import bplus.keys.BPlusNodeKey;
import bplus.nodes.BPlusIndexNode;
import bplus.nodes.BPlusLeafNode;
import bplus.nodes.BPlusNode;
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
