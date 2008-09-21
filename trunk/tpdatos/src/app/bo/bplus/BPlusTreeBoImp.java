package app.bo.bplus;

import java.util.Iterator;

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
import bplus.nodes.BPlusNode;
import exceptions.DataAccessException;

public class BPlusTreeBoImp implements BPlusTreeBo {

	private BPlusNodeDao nodeDao;
	
	public BPlusTreeBoImp() throws DataAccessException{
		this.nodeDao= new BPlusNodeDaoImp();
	}
	
	@Override
	public BPlusLeafElement getElement(BPlusElementKey elementKey)
			throws KeyNotFoundException, DataAccessException {
		BPlusNode root= this.getRootNode();
		return this.getElement(root,elementKey);
	}

	private BPlusLeafElement getElement(BPlusNode node,BPlusElementKey elementKey) throws KeyNotFoundException, DataAccessException {
		if (node.isLeafNode()){
			return (BPlusLeafElement)node.getElement(elementKey);
		}else{
			BPlusIndexNode indexNode= (BPlusIndexNode) node;
			BPlusNodeKey nextNode= indexNode.getLeftChildId();
			Iterator<BPlusElement> it= node.getElementsIterator();
			while (it.hasNext()){
				BPlusIndexElement auxElement= (BPlusIndexElement) it.next();
				if (auxElement.getKey().compareTo(elementKey)<=1){
					nextNode= auxElement.getRelatedNode();
				}
			}
			BPlusNode childNode=  nodeDao.getNode(nextNode);
			return this.getElement(childNode,elementKey);
		}
	}

	@Override
	public void insertElement(BPlusLeafElement element) throws DataAccessException {
		BPlusNode root= this.getRootNode();
		try {
			this.insertElement(root,element);
		} catch (NodeOverflowException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private void insertElement(BPlusNode node, BPlusLeafElement element) throws DataAccessException, NodeOverflowException {
		if (node.isLeafNode()){
			node.insertElement(element);
			nodeDao.updateNode(node);
		}else{
			BPlusIndexNode indexNode= (BPlusIndexNode) node;
			BPlusNodeKey nextNode= indexNode.getLeftChildId();
			Iterator<BPlusElement> it= node.getElementsIterator();
			while (it.hasNext()){
				BPlusIndexElement auxElement= (BPlusIndexElement) it.next();
				if (auxElement.getKey().compareTo(element.getKey())<=1){
					nextNode= auxElement.getRelatedNode();
				}
			}
			BPlusNode childNode=  nodeDao.getNode(nextNode);
			try {
				this.insertElement(childNode,element);
			} catch (NodeOverflowException e) {
				this.splitNode(childNode);
				this.insertElement(node,element);
			}
		}
	}
	
	private void splitNode(BPlusNode node) throws NodeOverflowException{
		if(node.isLeafNode()){
		}else{			
		}
	}

	public BPlusNode getRootNode(){
		// TODO Implementar!!!!
		return null;
	}
}
