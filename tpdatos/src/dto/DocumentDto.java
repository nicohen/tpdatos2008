package dto;

import java.util.ArrayList;
import java.util.List;

public class DocumentDto {
	private String document;
	private List<WordDto> words = null;
	
	public DocumentDto() {
		this.words = new ArrayList<WordDto>();
	}
	
	public List<WordDto> getWords() {
		return words;
	}

	public void addWord(WordDto word) {
		this.words.add(word);
	}

	public String getDocument() {
		return document;
	}

	public void setDocument(String document) {
		this.document = document;
	}
	
	@Override
	public String toString() {
		StringBuffer sb = new StringBuffer();
		for (WordDto dto : words) {
			sb.append(dto.toString());
		}
		return sb.toString();
	}

}
