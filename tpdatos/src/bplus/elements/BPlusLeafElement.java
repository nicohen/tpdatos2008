package bplus.elements;

import bplus.keys.BPlusElementKey;

public class BPlusLeafElement implements BPlusElement {

	BPlusElementKey elementKey;
	Integer size;
	
	public BPlusLeafElement(BPlusElementKey elementKey) {
		this.elementKey = elementKey;
	}
	
	@Override
	public BPlusElementKey getKey() {
		return this.elementKey;
	}

	@Override
	public Integer getSize() {
		return this.size;
	}

	@Override
	public void setKey(BPlusElementKey elementKey) {
		this.elementKey = elementKey;
	}

}
