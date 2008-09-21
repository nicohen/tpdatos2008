package bplus.nodes;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import bplus.elements.BPlusElement;
import bplus.exceptions.KeyNotFoundException;
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
	public BPlusElement getElement(BPlusNodeKey nodeKey) throws KeyNotFoundException {
		BPlusElement element = this.elements.get(nodeKey.getValue());
		if (element == null) throw new KeyNotFoundException();
		return element;
	}

	@Override
	public void insertElement(BPlusElement element) {
		this.elements.add(element);		
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
