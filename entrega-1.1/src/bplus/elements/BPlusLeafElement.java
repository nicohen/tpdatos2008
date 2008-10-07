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
	
	private boolean equalsValue( Integer value ) {
		if (this.value != null && value != null) {
			return this.value.equals(value);
		} else {
			if (this.value == null && value == null) {
				return true;
			} else {
				return false;
			}
		}
	}


	@Override
	public boolean equals(Object obj) {
		
		try {
			BPlusLeafElement elemento = (BPlusLeafElement)obj;

			return equalsKey(elemento.getKey() ) &&
					equalsValue(elemento.getValue());
			
		} catch (Exception e) {
			return false;
		}
		
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
