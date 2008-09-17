package bplus.nodes;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import bplus.elements.BPlusElement;
import bplus.keys.BPlusNodeKey;

/**
 * @author pablo
 *
 */
public abstract class AbstractBPlusNode implements BPlusNode {

	private BPlusNodeKey nodeKey;
	private List<BPlusElement> elements;
	private Integer maxNodeSize;
	private Integer currentNodeSize;
	
	public AbstractBPlusNode(Integer maxNodeSize) {
		this.maxNodeSize= maxNodeSize;
		this.elements= new ArrayList<BPlusElement>(); 
		this.currentNodeSize= 0;
	}
	
	@Override
	public BPlusElement getElement(BPlusNodeKey nodeKey) {
		return this.elements.get(nodeKey.getValue());
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
