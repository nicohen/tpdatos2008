package app.bo.bplus;

import java.util.Iterator;

import api.dao.BPlusTree.BPlusNodeDao;
import app.dao.bplus.BPlusNodeDaoImp;
import bplus.elements.BPlusElement;
import bplus.elements.BPlusIndexElement;
import bplus.nodes.BPlusIndexNode;
import bplus.nodes.BPlusNode;
import exceptions.DataAccessException;

public class BPlusTreeBoImp extends AbstractBPlusTreeBo {

	private String filename;
	private int nodeSize;
	
	public BPlusTreeBoImp( String filename, int nodeSize ) throws DataAccessException {
		this.filename= filename;
		this.nodeSize = nodeSize;
	}
	
	protected BPlusNodeDao createDao () throws DataAccessException {
		return new BPlusNodeDaoImp(filename,nodeSize);
	}
}
