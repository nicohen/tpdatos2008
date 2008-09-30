package bplus.nodes;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import bplus.elements.BPlusElement;
import bplus.elements.BPlusIndexElement;
import bplus.exceptions.KeyNotFoundException;
import bplus.keys.BPlusElementKey;
import bplus.keys.BPlusNodeKey;

/**
 * @author pablo
 *
 */
public abstract class AbstractBPlusNode implements BPlusNode {

	protected BPlusNodeKey nodeKey;
	protected List<BPlusElement> elements;
	
	public AbstractBPlusNode() {
		this.elements= new ArrayList<BPlusElement>();
	}
	
	@Override
	public BPlusElement getElement(BPlusElementKey elementKey) throws KeyNotFoundException {
		BPlusElement element = this.findElement(this.elements,elementKey);
		if (element == null) throw new KeyNotFoundException();
		return element;
	}

	private BPlusElement findElement(List<BPlusElement> elements,BPlusElementKey elementKey) {
		int start=0;
		int end=elements.size()-1;
		if (elements.size()==0) return null;
		BPlusElement auxElement=elements.get(0);
		if (auxElement.getKey().equals(elementKey)){
			return auxElement;
		}
		auxElement=elements.get(end);
		if(auxElement.getKey().equals(elementKey)){
			return auxElement;
		}
		while(end-start>0){
			int index=(end+start)/2;
			auxElement= elements.get(index);
			int result= auxElement.getKey().compareTo(elementKey);
			if (result<0){
					start=index;
			}else if(result==0){
					return auxElement;
			}else{
				end=index;
			}
		}
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
	public List<BPlusElement> getElements(){
		return elements;
	}
	
	@Override
	public void setElements(List<BPlusElement> elements) {
		this.elements=elements;
	}
	
	@Override
	public BPlusIndexElement getIndexElement(){
		BPlusIndexElement indexElement= new BPlusIndexElement(this.elements.get(0).getKey());
		indexElement.setRelatedNode(this.getNodeKey());
		return indexElement;
	}
	
	@Override
	public boolean equals(Object obj) {
		BPlusNode node= (BPlusNode)obj;
		return this.getNodeKey().equals(node.getNodeKey());
	}
}
