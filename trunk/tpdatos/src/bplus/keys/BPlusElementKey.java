package bplus.keys;

public class BPlusElementKey{

	private String word;

	public BPlusElementKey(String word) {
		this.word = word;
	}

	public String getValue() {
		return this.word;
	}

	public void setValue(String word) {
		this.word = word;
	}
	
	@Override
	public String toString() {
		return this.word;
	}
	
	public int compareTo(BPlusElementKey key) {
		return this.word.compareTo(key.word);
	}
}
