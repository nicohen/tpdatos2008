package bplus.nodes;

import bplus.elements.BPlusElement;
import bplus.keys.BPlusNodeKey;

public interface BPlusNode {
	public void insertElement(BPlusElement element);
	public BPlusElement getElement(BPlusNodeKey nodeKey);
}
