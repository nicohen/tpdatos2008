package api;

import app.bo.WordCollectorIndex;
import app.dao.documents.NullDocumentsDictionary;

public class WordCollectorQueryEngine extends QueryEngine {

	private WordCollectorIndex index;
	
	public WordCollectorQueryEngine() {
		super(
				new WordCollectorIndex(), 
				new NullDocumentsDictionary(),""
				);
		
		this.index = (WordCollectorIndex)this.getIndex();
	}
	
	public int getOcurrences(String word) {
		return index.getOcurrences(word);
	}

}
