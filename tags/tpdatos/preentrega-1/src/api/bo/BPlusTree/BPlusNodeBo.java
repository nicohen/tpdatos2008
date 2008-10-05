package api.bo.BPlusTree;

import bplus.elements.BPlusLeafElement;
import bplus.exceptions.KeyNotFoundException;
import bplus.keys.BPlusElementKey;

public interface BPlusNodeBo {
	public BPlusLeafElement getElement(BPlusElementKey elementKey) throws KeyNotFoundException;
	public void insertElement(BPlusLeafElement element);
	public void removeElement(BPlusElementKey elementKey) throws KeyNotFoundException;
	public void updateElement(BPlusLeafElement element)	throws KeyNotFoundException;
}
