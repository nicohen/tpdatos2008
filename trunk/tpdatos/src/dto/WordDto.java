package dto;

public class WordDto {
	
	private String word; 
	
	public WordDto( String word ) {
		this.word = word;
	}
	
	public String getWord() {
		return word;
	}

	public void setWord(String word) {
		this.word = word;
	}

	public String toString() {
		return word;
	}
	
}
