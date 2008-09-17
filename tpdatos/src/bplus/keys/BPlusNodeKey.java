package bplus.keys;

public class BPlusNodeKey extends BPlusKey<Integer> {

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

	@Override
	public int compareTo(BPlusKey element) {
		BPlusNodeKey intKey= (BPlusNodeKey) element;
		return id.compareTo(intKey.id);
	}

	@Override
	public int getSize() {
		// TODO Auto-generated method stub
		return 4;
	}
}
