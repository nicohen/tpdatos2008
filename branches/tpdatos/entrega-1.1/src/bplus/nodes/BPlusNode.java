package bplus.nodes;

import java.util.List;

import bplus.elements.BPlusElement;
import bplus.elements.BPlusIndexElement;
import bplus.exceptions.KeyNotFoundException;
import bplus.keys.BPlusElementKey;
import bplus.keys.BPlusNodeKey;

public interface BPlusNode {
	public void insertElement(BPlusElement element);
	public BPlusElement getElement(BPlusElementKey elementKey) throws KeyNotFoundException;
	public boolean isLeafNode();
	public BPlusNodeKey getNodeKey();
	public void setNodeKey(BPlusNodeKey key);
	public BPlusIndexElement getIndexElement();
	public List<BPlusElement> getElements();
	public void setElements(List<BPlusElement> elements);
	
}
