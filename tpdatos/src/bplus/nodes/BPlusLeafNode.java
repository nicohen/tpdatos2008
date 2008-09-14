package bplus.nodes;

import bplus.keys.BPlusNodeKey;

public class BPlusLeafNode extends AbstractBPlusNode {
	private BPlusNodeKey siblingNodeKey;

	public BPlusLeafNode(BPlusNodeKey nodeKey) {
		super(nodeKey);
	}

	public BPlusNodeKey getNextNodeKey() {
		return siblingNodeKey;
	}

	public void setNextNodeKey(BPlusNodeKey nextNodeKey) {
		this.siblingNodeKey = nextNodeKey;
	}
}
