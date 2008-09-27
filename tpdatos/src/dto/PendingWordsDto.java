package dto;

import java.util.ArrayList;
import java.util.List;

public class PendingWordsDto {
	private List<String> pendingWords = null;	
	
	public PendingWordsDto() {
		pendingWords = new ArrayList<String>();
	}

	public List<String> getPendingWords() {
		return pendingWords;
	}

	public void addPendingWord(String pendingWord) {
		this.pendingWords.add(pendingWord);
	}
	
	public int getPendingWordsQty() {
		return pendingWords.size();
	}
	
}