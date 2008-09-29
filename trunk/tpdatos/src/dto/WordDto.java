package dto;

import java.util.Iterator;
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
		return sb.toString().trim()+"\n";
	}

	@Override
	public int compareTo(WordDto o) {
		Iterator<String> myWord = words.iterator();
		Iterator<String> otherWord = o.words.iterator();
		while(myWord.hasNext() && otherWord.hasNext()) {
			int compare = myWord.next().compareTo(otherWord.next());
			if(compare!=0) {
				return compare;
			}
		}
		return (new Integer(words.size()).compareTo(o.words.size()))*-1;
	}

	@Override
	public boolean equals(Object arg0) {
		List<String> otherWords = ((WordDto)arg0).words;
		if(this.words.size()==otherWords.size()) {
			int wordCount = 0;
			for(String word : this.words) {
				if(!word.equals(otherWords.get(wordCount++))) {
					return false;
				}
			}
			return true;
		} else {
			return false;
		}
	}

}
