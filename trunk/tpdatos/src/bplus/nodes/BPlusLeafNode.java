package bplus.nodes;

import bplus.keys.BPlusNodeKey;

public class BPlusLeafNode extends AbstractBPlusNode {
	public BPlusLeafNode(BPlusNodeKey nodeKey) {
		super(nodeKey);
	}

	private BPlusNodeKey nextNodeKey;

	public BPlusNodeKey getNextNodeKey() {
		return nextNodeKey;
	}

	public void setNextNodeKey(BPlusNodeKey nextNodeKey) {
		this.nextNodeKey = nextNodeKey;
	}

	@Override
	public boolean isLeafNode() {
		return true;
	}
}
