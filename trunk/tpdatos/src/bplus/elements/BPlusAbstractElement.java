package bplus.elements;

import bplus.keys.BPlusElementKey;

public abstract class BPlusAbstractElement implements BPlusElement {
	
	protected BPlusElementKey elementKey;
	
	public BPlusAbstractElement(BPlusElementKey key) {
		this.elementKey=key;
	}
	
	public BPlusElementKey getKey() {
		return elementKey;
	}
	
	public void setKey(BPlusElementKey elementKey) {
		this.elementKey = elementKey;
	}

	public int compareTo(BPlusElement arg0) {
		return this.elementKey.compareTo(arg0.getKey());
	}
}
