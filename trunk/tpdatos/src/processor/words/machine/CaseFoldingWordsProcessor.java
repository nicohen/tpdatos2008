package processor.words.machine;

import dto.WordDto;
import processor.words.AbstractWordsProcessor;

public class CaseFoldingWordsProcessor extends AbstractWordsProcessor {

	public CaseFoldingWordsProcessor() {
		super();
	}
	
	@Override
	public void process(WordDto wordDto) {
		super.process(
				new WordDto( wordDto.toString().toLowerCase() )
				);
	}

}
