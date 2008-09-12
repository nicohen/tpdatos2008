package processor.words;

import dto.WordDto;

public abstract class AbstractWordsProcessor implements WordsProcessor {

	public AbstractWordsProcessor() {
		// TODO Auto-generated constructor stub
	}
	
	/* Serie de metodos para procesar los terminos */
	WordsProcessor next;
	
	public void setNext( WordsProcessor arg_next ) {
		next = arg_next;
	}
	
	public void process( WordDto worddto) {
		next.process(worddto);
	}
}
