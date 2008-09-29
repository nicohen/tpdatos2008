package app.bo.bplus;

import java.util.Iterator;

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
		this.nodeDao = new BPlusNodeDaoImp(filename,nodeSize);
		this.root=nodeDao.getRootNode();
	}
	
	public void dump() throws DataAccessException{
		dump(this.root);
	}
	private void dump(BPlusNode node) throws DataAccessException{
		System.out.println(node);
		if (node instanceof BPlusIndexNode) {
			BPlusIndexNode indexNode = (BPlusIndexNode) node;
			dump(this.nodeDao.getNode(indexNode.getLeftChild().getRelatedNode()));
			Iterator<BPlusElement> it= indexNode.getElements().iterator();
			while(it.hasNext()){
				dump(this.nodeDao.getNode(((BPlusIndexElement)it.next()).getRelatedNode()));
			}
		}
	}
}
