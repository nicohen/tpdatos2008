package bplus.elements;

import bplus.keys.BPlusElementKey;
import bplus.keys.BPlusNodeKey;


public class BPlusIndexElement extends BPlusAbstractElement{

	private BPlusNodeKey relatedNode;
	
	public BPlusIndexElement(BPlusElementKey key) {
		super(key);
	}

	public BPlusNodeKey getRelatedNode() {
		return relatedNode;
	}

	public void setRelatedNode(BPlusNodeKey relatedNode) {
		this.relatedNode = relatedNode;
	}
	
}
