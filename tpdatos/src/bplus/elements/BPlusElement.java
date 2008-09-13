package bplus.elements;

import bplus.keys.BPlusElementKey;

public interface BPlusElement {
	public BPlusElementKey getKey();
	public void setKey(BPlusElementKey elementKey);
	public Integer getSize();
}
