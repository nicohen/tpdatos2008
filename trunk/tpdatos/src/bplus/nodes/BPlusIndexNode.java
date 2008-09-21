package bplus.nodes;

import bplus.elements.BPlusIndexElement;
import bplus.elements.BPlusLeafElement;
import bplus.keys.BPlusNodeKey;


public class BPlusIndexNode extends AbstractBPlusNode {
	
	private BPlusNodeKey leftChildId;
	
	public BPlusIndexNode(BPlusNodeKey nodeKey) {
		super(nodeKey);
	}

	public void addElement(BPlusLeafElement element) {
		BPlusIndexElement indexNode= new BPlusIndexElement(element.getKey());
	}

	@Override
	public boolean isLeafNode() {
		return false;
	}

	public void setLeftChildId(BPlusNodeKey leftChildId) {
		this.leftChildId = leftChildId;
	}

	public BPlusNodeKey getLeftChildId() {
		return leftChildId;
	}
}
