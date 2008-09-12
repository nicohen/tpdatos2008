package processor.words;

import java.util.List;

import dto.WordDto;

public class WordsProcessorPipeline extends AbstractWordsProcessor {

	public WordsProcessorPipeline(List<AbstractWordsProcessor> pipeline, WordsProcessor next) {
		boolean has_first = false;
		AbstractWordsProcessor last = null;
		
		for ( AbstractWordsProcessor proc : pipeline ) {
			if ( !has_first ) {
				this.setNext( proc );	
				has_first = false;
			} else {
				last.setNext( proc );
			}
			
			last = proc;
		}
		
		last.setNext( next );
	}

	@Override
	public void process(WordDto wordDto) {
		super.process(wordDto);
	}
}
