package bplus.elements;

import bplus.keys.BPlusElementKey;

public interface BPlusElement extends Comparable<BPlusElement> {
	public BPlusElementKey getKey();
	public void setKey(BPlusElementKey elementKey);
}
