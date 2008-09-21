package bplus.nodes;

import java.util.Iterator;

import bplus.elements.BPlusElement;
import bplus.exceptions.KeyNotFoundException;
import bplus.keys.BPlusElementKey;
import bplus.keys.BPlusNodeKey;

public interface BPlusNode {
	public void insertElement(BPlusElement element);
	public BPlusElement getElement(BPlusElementKey elementKey) throws KeyNotFoundException;
	public boolean isLeafNode();
	public Iterator<BPlusElement> getElementsIterator();
	public BPlusNodeKey getNodeKey();
//	public void splitInto(BPlusNode node);
}
