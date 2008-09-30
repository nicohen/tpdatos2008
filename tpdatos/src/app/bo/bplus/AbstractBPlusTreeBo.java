package app.bo.bplus;

import java.util.Iterator;
import java.util.List;

import api.bo.BPlusTree.BPlusTreeBo;
import api.dao.BPlusTree.BPlusNodeDao;
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

// ABSTRACT FACTORY, asi la logica del bo puede abstraerse de la interfaz
// del dao, y el que instancia la clase tambien

abstract public class AbstractBPlusTreeBo implements BPlusTreeBo {

	private BPlusNodeDao nodeDao;
	private BPlusNode root;
	
	protected void setDao( BPlusNodeDao dao) throws DataAccessException {
		this.nodeDao = dao;
		this.root=nodeDao.getRootNode();
	}
		
	public AbstractBPlusTreeBo() throws DataAccessException{
		super();
	}
	
	@Override
	public BPlusLeafElement getElement(BPlusElementKey elementKey)
			throws KeyNotFoundException, DataAccessException {
		return this.getElement(root,elementKey);
	}

	private BPlusLeafElement getElement(BPlusNode node,BPlusElementKey elementKey) throws KeyNotFoundException, DataAccessException {
		if (node.isLeafNode()){
			return (BPlusLeafElement)node.getElement(elementKey);
		}else{
			BPlusIndexNode indexNode= (BPlusIndexNode) node;
			BPlusNodeKey nextNode= indexNode.getLeftChild().getRelatedNode();
			Iterator<BPlusElement> it= node.getElements().iterator();
			while (it.hasNext()){
				BPlusIndexElement auxElement= (BPlusIndexElement) it.next();
				if (auxElement.getKey().compareTo(elementKey)<=1){
					nextNode= auxElement.getRelatedNode();
				}
			}
			BPlusNode childNode=nodeDao.getNode(nextNode);
			return this.getElement(childNode,elementKey);
		}
	}

	@Override
	public void insertElement(BPlusLeafElement element) throws DataAccessException {
		try {
			this.insertElement(root,element);
		} catch (NodeOverflowException e) {
			try {
				BPlusIndexNode newRoot= new BPlusIndexNode();
				nodeDao.insertNode(newRoot);			
				splitNode(newRoot, root.getNodeKey());
				insertElement(newRoot,element);
				nodeDao.setRootNode(newRoot.getNodeKey());
				this.root=newRoot;
			} catch (NodeOverflowException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		}
	}

	private void insertElement(BPlusNode node, BPlusLeafElement element) throws DataAccessException, NodeOverflowException {
		if (node.isLeafNode()){
			node.insertElement(element);
			nodeDao.updateNode(node);
		}else{
			BPlusIndexNode indexNode= (BPlusIndexNode) node;
			BPlusNodeKey nextNode= indexNode.getLeftChild().getRelatedNode();
			Iterator<BPlusElement> it= node.getElements().iterator();
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
				this.splitNode(node,childNode.getNodeKey());
				this.insertElement(node,element);
			}
		}
	}
	
	private void splitNode(BPlusNode node, BPlusNodeKey ChildId) throws NodeOverflowException, DataAccessException{
		BPlusNode newNode;
		BPlusNode childNode=nodeDao.getNode(ChildId);
		List<BPlusElement> elements =childNode.getElements();
		int index= elements.size()/2;
		if(childNode.isLeafNode()){
			newNode= new BPlusLeafNode();
		}else{
			newNode= new BPlusIndexNode();
		}
		nodeDao.insertNode(newNode);
		while (index<elements.size()){
			newNode.insertElement(elements.get(index));
			elements.remove(index);
		}
		if(childNode.isLeafNode()){
			((BPlusLeafNode)childNode).setNextNodeKey(newNode.getNodeKey());
		}
		node.insertElement(newNode.getIndexElement());
		nodeDao.updateNode(node);
		nodeDao.updateNode(childNode);
		nodeDao.updateNode(newNode);
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
