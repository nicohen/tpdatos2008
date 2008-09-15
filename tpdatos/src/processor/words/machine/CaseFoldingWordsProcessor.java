package processor.words.machine;

import java.util.ArrayList;
import java.util.List;

import processor.words.AbstractWordsProcessor;
import dto.WordDto;

public class CaseFoldingWordsProcessor extends AbstractWordsProcessor {

	public CaseFoldingWordsProcessor() {
		super();
	}
	
	@Override
	public WordDto process(WordDto wordDto) {
		List<String> words = new ArrayList<String>();
		for (String word : wordDto.getWord()){
			words.add(word.toLowerCase());
		}
		return new WordDto(words);
	}

}
