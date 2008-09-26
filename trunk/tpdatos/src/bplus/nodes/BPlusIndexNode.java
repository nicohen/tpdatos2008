package bplus.nodes;

import bplus.elements.BPlusElement;
import bplus.elements.BPlusIndexElement;


public class BPlusIndexNode extends AbstractBPlusNode {
	
	private BPlusIndexElement leftChildId;
	
	public BPlusIndexNode() {
		super();
	}

	@Override
	public boolean isLeafNode() {
		return false;
	}

	@Override
	public void insertElement(BPlusElement element) {
		if (this.leftChildId.compareTo(element)<1){
			super.insertElement(this.leftChildId);
			this.leftChildId=(BPlusIndexElement)element;
		}
		super.insertElement(element);
	}
	
	public void setLeftChildId(BPlusIndexElement leftChildId) {
		this.leftChildId = leftChildId;
	}

	public BPlusIndexElement getLeftChildId() {
		return leftChildId;
	}
}
