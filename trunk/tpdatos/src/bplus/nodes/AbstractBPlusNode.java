package bplus.nodes;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

import bplus.elements.BPlusElement;
import bplus.exceptions.KeyNotFoundException;
import bplus.keys.BPlusElementKey;
import bplus.keys.BPlusNodeKey;

/**
 * @author pablo
 *
 */
public abstract class AbstractBPlusNode implements BPlusNode {

	private BPlusNodeKey nodeKey;
	private List<BPlusElement> elements;
	
	public AbstractBPlusNode( BPlusNodeKey nodeKey) {
		this.elements= new ArrayList<BPlusElement>();
		this.nodeKey = nodeKey;
	}
	
	@Override
	public BPlusElement getElement(BPlusElementKey elementKey) throws KeyNotFoundException {
		BPlusElement element = this.findElement(this.elements,elementKey);
		if (element == null) throw new KeyNotFoundException();
		return element;
	}

	private BPlusElement findElement(List<BPlusElement> elements,
			BPlusElementKey elementKey) {
		// TODO: implementar!!!
		return null;
	}

	@Override
	public void insertElement(BPlusElement element) {
		this.elements.add(element);
		Collections.sort(this.elements);
	}
	
	public BPlusNodeKey getNodeKey() {
		return nodeKey;
	}

	public void setNodeKey(BPlusNodeKey nodeKey) {
		this.nodeKey = nodeKey;
	}

	@Override
	public Iterator<BPlusElement> getElementsIterator(){
		return elements.iterator();
	}
}
