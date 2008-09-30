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
	public BPlusIndexElement getIndexElement(){
		BPlusIndexElement indexElement= new BPlusIndexElement(this.leftChild.getKey());
		indexElement.setRelatedNode(this.getNodeKey());
		return indexElement;
	}

	@Override
	public void insertElement(BPlusElement element) {
		if (this.leftChild==null){
			this.leftChild=(BPlusIndexElement)element;
		}else{
			if (this.leftChild.compareTo(element)==1){
				super.insertElement(this.leftChild);
				this.leftChild=(BPlusIndexElement)element;
			}else{
				super.insertElement(element);		
			}
		}
	}
	
	public void setLeftChild(BPlusIndexElement leftChild) {
		this.leftChild = leftChild;
	}

	public BPlusIndexElement getLeftChild() {
		return leftChild;
	}
	
	@Override
	public String toString() {
		StringBuilder sb= new StringBuilder();
		sb.append("[ id:");
		sb.append(this.nodeKey.toString());
		sb.append(" , left:");
		sb.append(this.leftChild.toString());
		sb.append(" , elementos:");
		sb.append(this.elements.toString());
		sb.append("]");
		return sb.toString();
	}
	
}
