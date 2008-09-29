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
	
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append("[ key:");
		sb.append(this.elementKey.toString());
		sb.append(" , value:");
		sb.append(this.value.toString());
		sb.append("]");
		return sb.toString();
	}
}
