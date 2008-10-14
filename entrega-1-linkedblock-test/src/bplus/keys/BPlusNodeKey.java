package bplus.keys;

public class BPlusNodeKey implements Comparable<BPlusNodeKey>{

	private Integer id;
	
	public BPlusNodeKey(){
		super();
	}
	
	public BPlusNodeKey(Integer id) {
		this.id = id;
	}
	
	public Integer getValue() {
		return this.id;
	}

	public void setValue(Integer id) {
		this.id = id;
	}

	@Override
	public String toString() {
		return String.valueOf(id);
	}

	public int compareTo(BPlusNodeKey element) {
		return this.id.compareTo(element.id);
	}
}
