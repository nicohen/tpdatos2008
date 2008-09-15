package processor.words.machine;

import processor.words.AbstractWordsProcessor;
import dto.LineDto;

public class StemmerWordsProcessor extends AbstractWordsProcessor {

	public StemmerWordsProcessor() {
		super();
	}
	
	@Override
	public LineDto process(LineDto pipelineDto) {
		return pipelineDto;
	}

}
