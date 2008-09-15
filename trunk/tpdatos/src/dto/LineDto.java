package dto;

import java.util.ArrayList;
import java.util.List;

public class LineDto implements Comparable<LineDto> {
	
	//Las palabras que contiene esa linea de texto
	private List<WordDto> words = null;

	//Toda la linea de texto en crudo
	private String rawLine;

	public LineDto(String rawLine) {
		words = new ArrayList<WordDto>();
		this.rawLine = rawLine;
	}

	public String getRawLine() {
		return rawLine;
	}

	public void addWord(WordDto word) {
		words.add(word);
	}
	
	public List<WordDto> getWordsPipeline() {
		return words;
	}

	public WordDto getWord(int index) {
		return words.get(index); 
	}
	
	@Override
	public String toString() {
		StringBuffer sb = new StringBuffer();
		for (WordDto dto : words ) {
			sb.append(dto.toString());
		}
		return sb.toString();
	}

	@Override
	public int compareTo(LineDto o) {
		if (words.size()<o.words.size()) { 
			return 1;
		} else {
			if (words.size()>o.words.size()) { 
				return -1;
			} else {
				if (rawLine.compareTo(o.rawLine)>0) {
					return 1;
				} else if (rawLine.compareTo(o.rawLine)<0) {
					return -1;
				} else {
					return 0;
				}
			}
		}
	}

}
