package api;

import app.bo.WordCollectorIndex;
import app.dao.documents.NullDocumentsDictionary;

public class WordCollectorQueryEngine extends QueryEngine {

	private WordCollectorIndex index;
	
	public WordCollectorQueryEngine(String word) {
		super(
				new WordCollectorIndex(word), 
				new NullDocumentsDictionary(),""
				);
		
		this.index = (WordCollectorIndex)this.getIndex();
	}
	
	public int getOcurrences() {
		return index.getOcurrences();
	}

}
