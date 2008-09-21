package bplus.nodes;

import java.util.Iterator;

import bplus.elements.BPlusElement;
import bplus.keys.BPlusNodeKey;

public interface BPlusNode {
	public void insertElement(BPlusElement element);
	public BPlusElement getElement(BPlusNodeKey nodeKey);
	public boolean isLeafNode();
	public Iterator<BPlusElement> getElementsIterator();
	public BPlusNodeKey getNodeKey();
	public void splitInto(BPlusNode node);
}
