package processor.words.machine;

import dto.WordDto;
import processor.words.AbstractWordsProcessor;

public class CaseFoldingWordsProcessor extends AbstractWordsProcessor {

	public CaseFoldingWordsProcessor() {
		super();
	}
	
	@Override
	public void process(WordDto wordDto) {
		wordDto.setWord(wordDto.toString().toLowerCase());
		super.process(wordDto);
	}

}
