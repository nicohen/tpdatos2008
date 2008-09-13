package bplus.nodes;

import java.util.List;

import bplus.elements.BPlusElement;
import bplus.keys.BPlusNodeKey;

public class AbstractBPlusNode implements BPlusNode {

	List<BPlusElement> elements;
	Integer maxNodeSize;
	Integer currentNodeSize;
	
	public AbstractBPlusNode() {}
	
	@Override
	public BPlusElement getElement(BPlusNodeKey nodeKey) {
		return this.elements.get(nodeKey.getValue());
	}

	@Override
	public void insertElement(BPlusElement element) {
		this.elements.add(element);		
	}

}
