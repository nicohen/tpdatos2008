package processor.words;

import java.util.ArrayList;
import java.util.List;

import processor.words.machine.AccentTrimmerWordsProcessor;
import processor.words.machine.CaseFoldingWordsProcessor;
import processor.words.machine.StemmerWordsProcessor;
import processor.words.machine.StopwordsWordsProcessor;
import processor.words.machine.UmlautTrimmerWordsProcessor;

public class WordsProcessorPipelineFactory {
	
	public WordsProcessorPipeline getProcessor() {
		List<WordsProcessor> pipeline = new ArrayList<WordsProcessor>();
		pipeline.add(new UmlautTrimmerWordsProcessor());
		pipeline.add(new AccentTrimmerWordsProcessor());
		pipeline.add(new CaseFoldingWordsProcessor());
		pipeline.add(new StopwordsWordsProcessor());
		pipeline.add(new StemmerWordsProcessor());
		
		return (new WordsProcessorPipeline(pipeline));
	}
	
}
