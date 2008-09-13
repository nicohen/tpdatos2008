package bplus.nodes;

import bplus.keys.BPlusNodeKey;

public class BPlusLeafNode extends AbstractBPlusNode {
	private BPlusNodeKey nextNodeKey;

	public BPlusNodeKey getNextNodeKey() {
		return nextNodeKey;
	}

	public void setNextNodeKey(BPlusNodeKey nextNodeKey) {
		this.nextNodeKey = nextNodeKey;
	}
}
