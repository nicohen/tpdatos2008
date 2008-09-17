package documents.keys;

import bplus.keys.BPlusKey;

public class DocumentIndexKey extends BPlusKey<Integer> {

	private Integer id;
	
	public DocumentIndexKey() {}
	
	public DocumentIndexKey(Integer id) {
		this.id = id;
	}
	
	@Override
	public Integer getValue() {
		return id;
	}

	@Override
	public void setValue(Integer id) {
		this.id = id;
	}

	@Override
	public String toString() {
		return String.valueOf(id);
	}

	@Override
	public int compareTo(BPlusKey element) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int getSize() {
		// TODO Auto-generated method stub
		return 0;
	}
	
}
