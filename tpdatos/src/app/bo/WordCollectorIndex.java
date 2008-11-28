package app.bo;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

import api.Index;
import exceptions.BusinessException;

// Word collector simplemente almacena todas las palabras

public class WordCollectorIndex implements Index {

	int ocurrencias;
	private String word;
	
	public WordCollectorIndex(String word ) {
		this.word = word;
		this.ocurrencias = 0;
	}
	
	public List<Integer> getDocuments(String word) throws BusinessException {
		return new ArrayList<Integer>();
	}

	public void insertWord(String word, Integer documento)
			throws BusinessException {

		if (word.equals(this.word)) {
			ocurrencias++;
		}
	}

	public int getOcurrences() {
		return ocurrencias;
	}

	public Iterator<Integer> getDocumentsIterator(String word) throws BusinessException {
		return this.getDocuments(word).iterator();
	}

}
