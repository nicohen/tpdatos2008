package bplus.keys;

public class BPlusElementKey extends BPlusKey<String>{

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
	
	public int compareTo(BPlusKey key) {
		BPlusElementKey stringKey = (BPlusElementKey) key;
		return word.compareTo(stringKey.word);
	}

	@Override
	public int getSize() {
		return 1+2*word.length();		
	}
}
