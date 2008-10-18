package dto;

import java.util.ArrayList;
import java.util.List;

import exceptions.PipelineOverflowException;

public class StopwordsPipelineDto {
	private List<String> wordsPipeline = null;
	
	public StopwordsPipelineDto() {
		this.wordsPipeline = new ArrayList<String>();
	}

	public List<String> getWords() {
		return this.wordsPipeline;
	}

	public void addWord(String word) throws PipelineOverflowException {
		if(getSize() < getMaxSize()) {
			this.wordsPipeline.add(word);
		} else {
			throw new PipelineOverflowException("Overflow en pipeline al intentar insertar un elemento");
		}
	}
		
	public int getSize() {
		return this.wordsPipeline.size();
	}
	
	public int getMaxSize() {
		return 5;
	}
	
	public boolean isEmpty() {
		return this.wordsPipeline.isEmpty();
	}
	
	public void removeWord(int index) {
		this.wordsPipeline.remove(index);
	}

	public void removeWords(int wordsQty) {
		for(int i=0;i<wordsQty;i++) {
			this.wordsPipeline.remove(0);
		}
	}

	public String getWord(int index) {
		return this.wordsPipeline.get(index);
	}

	public boolean isFull() {
		return getSize()==getMaxSize();
	}

	public String getFirstWord() {
		return this.wordsPipeline.get(0);
	}
}
