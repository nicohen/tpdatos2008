package bplus.nodes;

import bplus.elements.BPlusElement;
import bplus.exceptions.KeyNotFoundException;
import bplus.exceptions.NodeOverflowException;
import bplus.keys.BPlusElementKey;

public interface BPlusNode {
	public void insertElement(BPlusElement element) throws NodeOverflowException;
	public BPlusElement getElement(BPlusElementKey elementKey) throws KeyNotFoundException;
}
