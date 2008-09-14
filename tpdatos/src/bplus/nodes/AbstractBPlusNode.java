package bplus.nodes;

import java.util.HashMap;
import java.util.Map;

import bplus.elements.BPlusElement;
import bplus.exceptions.KeyNotFoundException;
import bplus.exceptions.NodeOverflowException;
import bplus.keys.BPlusElementKey;
import bplus.keys.BPlusNodeKey;

public class AbstractBPlusNode implements BPlusNode {

	Map<BPlusElementKey, BPlusElement> elements = 
				new HashMap<BPlusElementKey, BPlusElement>();
	
	Integer maxNodeSize;
	Integer currentNodeSize;
	
	public AbstractBPlusNode() {
		currentNodeSize = 0;
	}
	
	@Override
	public BPlusElement getElement(BPlusElementKey elementKey) throws KeyNotFoundException {
		
		BPlusElement currentElement = elements.get(elementKey);
		
		if ( currentElement == null) {
			throw new KeyNotFoundException();
		}
		
		return currentElement;
	}

	@Override
	public void insertElement(BPlusElement element) throws NodeOverflowException {
		//this.elements.add(element);
		
		BPlusElement currentElement = elements.get(element.getKey() );
		
		if (currentElement != null) {
			if (currentElement.equals(element)) {
				
				if (currentNodeSize - currentElement.getSize() + element.getSize() >= maxNodeSize) {
					throw new NodeOverflowException();
				}
				
				currentNodeSize -= currentElement.getSize();
				elements.remove(currentElement.getKey() );
			} else {
				if (currentNodeSize + element.getSize() >= maxNodeSize) {
					throw new NodeOverflowException();
				}
			}
		} else {
			if (currentNodeSize + element.getSize() >= maxNodeSize) {
				throw new NodeOverflowException();
			}
		}
		
		currentNodeSize += element.getSize();
		elements.put(element.getKey(), element);
		
	}
	
	public void deleteElement(BPlusNodeKey key) {

		BPlusElement currentElement = elements.get(key);
		if (currentElement != null) {
			currentNodeSize -= currentElement.getSize();
			elements.remove(key);
		}
		
	}

	
}
