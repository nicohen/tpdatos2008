package app.bo.bplus;

import java.util.HashMap;
import java.util.Map;

import api.bo.BPlusTree.BPlusTreeBo;
import bplus.elements.BPlusLeafElement;
import bplus.exceptions.KeyNotFoundException;
import bplus.keys.BPlusElementKey;

public class BPlusTreeBoTest implements BPlusTreeBo {

	
	private Map<String, BPlusLeafElement> map = new HashMap<String, BPlusLeafElement>();
	
	@Override
	public BPlusLeafElement getElement(BPlusElementKey elementKey)
			throws KeyNotFoundException {
		// TODO Auto-generated method stub
		BPlusLeafElement element = map.get(elementKey.getValue());
		if ( element == null) {
			throw new KeyNotFoundException();
		} else {
			return element;
		}
	}

	@Override
	public void insertElement(BPlusLeafElement element) {
		// TODO Auto-generated method stub
		map.put(element.getKey().getValue(), element);

	}

	public void removeElement(BPlusElementKey elementKey)
			throws KeyNotFoundException {
		// TODO Auto-generated method stub
		if (map.get(elementKey) == null) throw new KeyNotFoundException();
		map.remove(elementKey);

	}

	public void updateElement(BPlusLeafElement element)
			throws KeyNotFoundException {
		// TODO Auto-generated method stub
		if (map.get(element.getKey().getValue() ) == null) throw new KeyNotFoundException();
		map.put(element.getKey().getValue(), element);
	}

}
