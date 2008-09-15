package processor.words.machine;

import processor.words.AbstractWordsProcessor;
import dto.LineDto;
import dto.WordDto;

public class CaseFoldingWordsProcessor extends AbstractWordsProcessor {

	public CaseFoldingWordsProcessor() {
		super();
	}
	
	@Override
	public LineDto process(LineDto pipelineDto) {
		LineDto otherPipelineDto = new LineDto(pipelineDto.getRawLine());
		for (WordDto word : pipelineDto.getWordsPipeline()) {
			otherPipelineDto.addWord(new WordDto(word.toString().toLowerCase()));
		}
		return otherPipelineDto;
	}

}
