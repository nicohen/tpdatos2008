package documents.keys;

public class DocumentIndexKey {

	private Integer id;
	
	public DocumentIndexKey() {}
	
	public DocumentIndexKey(Integer id) {
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
/*
	public int compareTo(BPlusKey element) {
		// TODO Auto-generated method stub
		return 0;
	}*/
	
}
