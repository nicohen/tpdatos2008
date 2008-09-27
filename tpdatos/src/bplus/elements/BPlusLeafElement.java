package bplus.elements;

import bplus.keys.BPlusElementKey;

public class BPlusLeafElement extends BPlusAbstractElement {

	private Integer value;
	
	public Integer getValue() {
		return value;
	}
	
	public BPlusLeafElement(BPlusElementKey key) {
		super(key);
	}

	public BPlusLeafElement(BPlusElementKey key, Integer value ) {
		super(key);
		this.setValue(value);
	}
	
	public void setValue(Integer value){
		this.value= value;
	}
}
