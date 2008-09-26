package bplus.nodes;

import bplus.keys.BPlusNodeKey;


public class BPlusIndexNode extends AbstractBPlusNode {
	
	private BPlusNodeKey leftChildId;
	
	public BPlusIndexNode() {
		super();
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
