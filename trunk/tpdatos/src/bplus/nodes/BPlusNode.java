package bplus.nodes;

import bplus.elements.BPlusElement;
import bplus.exceptions.KeyNotFoundException;
import bplus.exceptions.NodeOverflowException;
import bplus.keys.BPlusNodeKey;

public interface BPlusNode {
	public void insertElement(BPlusElement element) throws NodeOverflowException;
	public BPlusElement getElement(BPlusNodeKey nodeKey) throws KeyNotFoundException;
}
