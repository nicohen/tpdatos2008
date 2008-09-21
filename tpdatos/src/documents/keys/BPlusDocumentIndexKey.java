package documents.keys;

public class BPlusDocumentIndexKey {

	private Integer id;
	
	public BPlusDocumentIndexKey() {
		super();
	}
	
	public BPlusDocumentIndexKey(Integer id) {
		this.id = id;
	}
	
	public Integer getValue() {
		return id;
	}

	public void setValue(Integer id) {
		this.id = id;
	}

	public String toString() {
		return String.valueOf(id);
	}

	public int compareTo(BPlusDocumentIndexKey element) {
		BPlusDocumentIndexKey intKey= element;
		return id.compareTo(intKey.id);
	}
}
