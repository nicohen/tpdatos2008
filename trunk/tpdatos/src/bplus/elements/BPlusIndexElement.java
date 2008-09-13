package bplus.elements;

import bplus.keys.BPlusElementKey;

public class BPlusIndexElement implements BPlusElement{

	BPlusElementKey elementKey;
	Integer size;
	
	public BPlusIndexElement(BPlusElementKey elementKey) {
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
