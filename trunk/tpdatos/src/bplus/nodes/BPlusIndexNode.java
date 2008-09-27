package bplus.nodes;

import bplus.elements.BPlusElement;
import bplus.elements.BPlusIndexElement;


public class BPlusIndexNode extends AbstractBPlusNode {
	
	private BPlusIndexElement leftChild;
	
	public BPlusIndexNode() {
		super();
	}

	@Override
	public boolean isLeafNode() {
		return false;
	}

	@Override
	public void insertElement(BPlusElement element) {
		if (this.leftChild.compareTo(element)<1){
			super.insertElement(this.leftChild);
			this.leftChild=(BPlusIndexElement)element;
		}
		super.insertElement(element);
	}
	
	public void setLeftChild(BPlusIndexElement leftChild) {
		this.leftChild = leftChild;
	}

	public BPlusIndexElement getLeftChild() {
		return leftChild;
	}
}
