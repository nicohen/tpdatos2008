package processor.words.machine;

import java.util.HashSet;

import processor.words.AbstractWordsProcessor;
import dto.WordDto;

public class StopwordsWordsProcessor extends AbstractWordsProcessor {

	private HashSet<String> set;
	
	public StopwordsWordsProcessor() {
		super();
	}
	
	void addStopword( String word ) {
		set.add(word);
	}
	
	@Override
	public WordDto process(WordDto wordDto) {
		return wordDto;
	}

}
