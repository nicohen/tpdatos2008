package bplus.nodes;

import bplus.elements.BPlusIndexElement;
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
	
	public BPlusIndexElement getIndexElement(){
		BPlusIndexElement indexElement= new BPlusIndexElement(this.elements.get(0).getKey());
		indexElement.setRelatedNode(this.getNodeKey());
		return indexElement;
	}
}
