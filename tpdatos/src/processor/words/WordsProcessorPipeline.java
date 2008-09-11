package processor.words;

import java.util.List;

import dto.WordDto;

public class WordsProcessorPipeline implements WordsProcessor {

	private List<WordsProcessor> pipeline = null;
	
	public WordsProcessorPipeline(List<WordsProcessor> pipeline) {
		this.pipeline = pipeline;
	}

	@Override
	public String process(WordDto wordDto) {
		
		for (WordsProcessor wordsProcessor : pipeline) {
			wordsProcessor.process(wordDto);
		}
		
		return wordDto.toString();
	}
}
