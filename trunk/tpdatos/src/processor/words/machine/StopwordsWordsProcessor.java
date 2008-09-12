package processor.words.machine;

import java.util.HashSet;

import dto.WordDto;
import processor.words.AbstractWordsProcessor;

public class StopwordsWordsProcessor extends AbstractWordsProcessor {

	private HashSet<String> set;
	
	public StopwordsWordsProcessor() {
		super();
	}
	
	void addStopword( String word ) {
		set.add(word);
	}
	
	@Override
	public void process(WordDto wordDto) {
		if ( ! set.contains(wordDto.toString() )) {
			super.process(wordDto);
		}
	}

}
