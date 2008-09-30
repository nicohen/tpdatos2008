package bplus.nodes;

import bplus.keys.BPlusNodeKey;

public class BPlusLeafNode extends AbstractBPlusNode {
	public BPlusLeafNode() {
		super();
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
	
	@Override
	public String toString() {
		StringBuilder sb= new StringBuilder();
		sb.append("[ id:");
		sb.append(this.nodeKey);
		sb.append(" , next:");
		sb.append(this.nextNodeKey);
		sb.append(" , elementos:");
		sb.append(this.elements);
		sb.append("]");
		return sb.toString();
	}
	
}
