package bplus.keys;

public class BPlusNodeKey implements BPlusKey<Integer> {

	private Integer id;
	
	public BPlusNodeKey() {}
	
	public BPlusNodeKey(Integer id) {
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
