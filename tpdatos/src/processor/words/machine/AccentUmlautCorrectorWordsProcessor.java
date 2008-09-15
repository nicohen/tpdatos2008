package processor.words.machine;

import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;

import processor.words.AbstractWordsProcessor;
import dto.LineDto;
import dto.WordDto;

public class AccentUmlautCorrectorWordsProcessor extends AbstractWordsProcessor {

	public AccentUmlautCorrectorWordsProcessor() {
		super();
	}

	@Override
	public LineDto process(LineDto pipelineDto) {
		LineDto otherPipelineDto = new LineDto(pipelineDto.getRawLine());
		for (WordDto word : pipelineDto.getWordsPipeline()) {
			try {
				otherPipelineDto.addWord(new WordDto(URLDecoder.decode(word.toString(), "UTF-8")));
			} catch (UnsupportedEncodingException e) {
				otherPipelineDto.addWord(word);
			}
		}
		return otherPipelineDto;
	}
	
}
