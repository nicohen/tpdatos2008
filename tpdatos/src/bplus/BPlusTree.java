package bplus;

import java.util.Iterator;

import bplus.elements.BPlusElement;
import bplus.elements.BPlusIndexElement;
import bplus.elements.BPlusLeafElement;
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
		this.insertElement(this.root,element);
	}
	
	private void insertElement(BPlusNode node, BPlusLeafElement element){
		if(node.isLeafNode()){
			node.insertElement(element);
		}else{
			BPlusIndexNode indexNode= (BPlusIndexNode) node;
			BPlusNodeKey nextNode= indexNode.getLeftChildId();
			Iterator<BPlusElement> it= node.getElementsIterator();
			while (it.hasNext()){
				BPlusIndexElement auxElement= (BPlusIndexElement) it.next();
				if (auxElement.getKey().compareTo(element.getKey())<1){
					nextNode= auxElement.getRelatedNode();
				}
			}
			insertElement(nodeHandler.getNode(nextNode), element);
		}
	}
	
	public BPlusLeafNode getElement(BPlusElementKey key){
		//TODO: implementar!!!
		return null;
	}
	
}
