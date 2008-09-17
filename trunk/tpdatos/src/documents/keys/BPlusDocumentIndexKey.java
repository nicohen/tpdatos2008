package documents.keys;

import bplus.keys.BPlusKey;
import bplus.keys.BPlusNodeKey;

public class BPlusDocumentIndexKey extends BPlusKey<Integer> {

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

	@Override
	public int compareTo(BPlusKey element) {
		BPlusDocumentIndexKey intKey= (BPlusDocumentIndexKey) element;
		return id.compareTo(intKey.id);
	}

	@Override
	public int getSize() {
		// TODO Auto-generated method stub
		return 0;
	}
	
}
