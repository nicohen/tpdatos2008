package app.bo.bplus;

import java.util.HashMap;
import java.util.Map;

import bplus.elements.BPlusLeafElement;
import bplus.exceptions.KeyNotFoundException;
import bplus.keys.BPlusElementKey;
import exceptions.DataAccessException;

public class BPlusTreeBoTest extends AbstractBPlusTreeBo {

	
	public BPlusTreeBoTest() {
		super();
		// TODO Auto-generated constructor stub
	}

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
