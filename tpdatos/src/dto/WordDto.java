package dto;

import java.util.List;


public class WordDto implements Comparable<WordDto> {
	private List<String> words = null;
	
	public WordDto(List<String> words) {
		this.words = words;
	}
	
	public List<String> getWord() {
		return words;
	}

	@Override
	public String toString() {
		StringBuffer sb = new StringBuffer();
		for (String dto : words ) {
			sb.append(dto.toString()+" ");
		}
		return sb.toString().trim();
	}

	@Override
	public int compareTo(WordDto o) {
		if (words.size()<o.getWord().size()) { 
			return 1;
		} else {
			if (words.size()>o.getWord().size()) { 
				return -1;
			} else {
				if (toString().compareTo(o.toString())>0) {
					return 1;
				} else if (toString().compareTo(o.toString())<0) {
					return -1;
				} else {
					return 0;
				}
			}
		}
	}


}
