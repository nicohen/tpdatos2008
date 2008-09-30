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
		if ( this.nodeKey != null) {
			sb.append(this.nodeKey.toString());
		} else {
			sb.append("NULL");
		}
		sb.append(" , next:");
		if ( this.nextNodeKey != null) {
			sb.append(this.nextNodeKey.toString());
		} else {
			sb.append("NULL");
		}
		sb.append(" , elementos:");
		if ( this.elements != null) {
			sb.append(this.elements.toString());
		} else {
			sb.append("NULL");
		}
		sb.append("]");
		return sb.toString();
	}
	
}
