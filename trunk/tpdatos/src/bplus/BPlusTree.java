package bplus;

import java.util.Iterator;

import bplus.elements.BPlusElement;
import bplus.elements.BPlusIndexElement;
import bplus.elements.BPlusLeafElement;
import bplus.exceptions.NodeNotFoundException;
import bplus.exceptions.NodeOverflowException;
import bplus.keys.BPlusElementKey;
import bplus.keys.BPlusNodeKey;
import bplus.nodes.BPlusIndexNode;
import bplus.nodes.BPlusLeafNode;
import bplus.nodes.BPlusNode;

public class BPlusTree {

	private int nodeSize;
	private BPlusNode root;
	private NodeHandler nodeHandler;
	
	public BPlusTree(int nodeSize) {
		this.nodeSize= nodeSize;
		this.root= nodeHandler.newLeafNode(this.nodeSize);
	}
	
	public void addElement(BPlusLeafElement element){
		try {
			this.insertElement(this.root,element);
		} catch (NodeOverflowException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (NodeNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private void insertElement(BPlusNode node, BPlusLeafElement element) throws NodeOverflowException,NodeNotFoundException {
		if(node.isLeafNode()){
			node.insertElement(element);
			nodeHandler.updateNode(node);
		}else{
			BPlusIndexNode indexNode= (BPlusIndexNode) node;
			BPlusNodeKey nextNode= indexNode.getLeftChildId().getRelatedNode();
			Iterator<BPlusElement> it= node.getElements().iterator();
			while (it.hasNext()){
				BPlusIndexElement auxElement= (BPlusIndexElement) it.next();
				if (auxElement.getKey().compareTo(element.getKey())<1){
					nextNode= auxElement.getRelatedNode();
				}
			}
			BPlusNode childNode=  nodeHandler.getNode(nextNode);
			try{
				insertElement(childNode, element);
			}catch(NodeOverflowException exception){
				BPlusNode newNode = nodeHandler.newLeafNode(nodeSize);
				
				// FIXME: resolver la division del nodo
				
			//	childNode.splitInto(newNode);
				nodeHandler.updateNode(childNode);
				nodeHandler.updateNode(newNode);
			}
		}
	}
	
	public BPlusLeafNode getElement(BPlusElementKey key){
		//TODO: implementar!!!
		return null;
	}
	
}
