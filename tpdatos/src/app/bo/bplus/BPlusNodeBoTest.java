package app.bo.bplus;

import java.util.HashMap;

import api.bo.BPlusTree.BPlusNodeBo;
import bplus.elements.BPlusLeafElement;
import bplus.exceptions.KeyNotFoundException;
import bplus.keys.BPlusElementKey;

public class BPlusNodeBoTest implements BPlusNodeBo {

	
	private HashMap<BPlusElementKey, BPlusLeafElement> map;
	
	@Override
	public BPlusLeafElement getElement(BPlusElementKey elementKey)
			throws KeyNotFoundException {
		// TODO Auto-generated method stub
		BPlusLeafElement element = map.get(elementKey);
		if ( element == null) {
			throw new KeyNotFoundException();
		} else {
			return element;
		}
	}

	@Override
	public void insertElement(BPlusLeafElement element) {
		// TODO Auto-generated method stub
		map.put(element.getKey(), element);

	}

	@Override
	public void removeElement(BPlusElementKey elementKey)
			throws KeyNotFoundException {
		// TODO Auto-generated method stub
		if (map.get(elementKey) == null) throw new KeyNotFoundException();
		map.remove(elementKey);

	}

	@Override
	public void updateElement(BPlusLeafElement element)
			throws KeyNotFoundException {
		// TODO Auto-generated method stub
		if (map.get(element.getKey()) == null) throw new KeyNotFoundException();
		map.put(element.getKey(), element);
	}

}
