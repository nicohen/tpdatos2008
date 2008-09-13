package documents.keys;

import bplus.keys.BPlusKey;

public class BPlusDocumentIndexKey implements BPlusKey<Integer> {

	private Integer id;
	
	public BPlusDocumentIndexKey() {}
	
	public BPlusDocumentIndexKey(Integer id) {
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
	
}
