package bplus.keys;

public class BPlusElementKey implements BPlusKey<String> {

	private String word;

	public BPlusElementKey() {}
	
	public BPlusElementKey(String word) {
		this.word = word;
	}

	@Override
	public String getValue() {
		return word;
	}

	@Override
	public void setValue(String word) {
		this.word = word;
	}
	
	@Override
	public String toString() {
		return word;
	}

}
