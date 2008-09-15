package processor.words;

import java.util.ArrayList;
import java.util.List;

import processor.words.machine.AccentUmlautCorrectorWordsProcessor;
import processor.words.machine.CaseFoldingWordsProcessor;
import processor.words.machine.StemmerWordsProcessor;
import processor.words.machine.StopwordsWordsProcessor;

public class WordsProcessorPipelineFactory {
	
	public static List<AbstractWordsProcessor> getPipeline() {
		List<AbstractWordsProcessor> pipeline = new ArrayList<AbstractWordsProcessor>();
		pipeline.add(new AccentUmlautCorrectorWordsProcessor());
		pipeline.add(new CaseFoldingWordsProcessor());
		pipeline.add(new StopwordsWordsProcessor());
		pipeline.add(new StemmerWordsProcessor());
		
		return pipeline;
	}
	
}
