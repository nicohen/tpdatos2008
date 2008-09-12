package processor.words;

import java.util.ArrayList;
import java.util.List;

import processor.words.machine.AccentTrimmerWordsProcessor;
import processor.words.machine.CaseFoldingWordsProcessor;
import processor.words.machine.StemmerWordsProcessor;
import processor.words.machine.StopwordsWordsProcessor;
import processor.words.machine.UmlautTrimmerWordsProcessor;

import dto.WordDto;

public class WordsProcessFacade implements WordsProcessor {

	private WordsProcessorPipeline internal;
	
	public WordsProcessFacade(  WordsProcessor next) {
		List<AbstractWordsProcessor> pipeline = new ArrayList<AbstractWordsProcessor>();
		pipeline.add(new UmlautTrimmerWordsProcessor());
		pipeline.add(new AccentTrimmerWordsProcessor());
		pipeline.add(new CaseFoldingWordsProcessor());
		pipeline.add(new StopwordsWordsProcessor());
		pipeline.add(new StemmerWordsProcessor());
		
		internal = new WordsProcessorPipeline( pipeline, next);
	}

	public void process(WordDto wordDto) {
		// TODO Auto-generated method stub
		internal.process(wordDto);
	}

}
