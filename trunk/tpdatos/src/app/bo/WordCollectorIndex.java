package app.bo;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import api.Index;
import exceptions.BusinessException;

// Word collector simplemente almacena todas las palabras

public class WordCollectorIndex implements Index {

	private Map<String,Integer> words = new HashMap<String,Integer>();
	
	public List<Integer> getDocuments(String word) throws BusinessException {
		return new ArrayList<Integer>();
	}

	public void insertWord(String word, Integer documento)
			throws BusinessException {

		Integer cantidad = words.get(word);
		if (cantidad == null) cantidad = 0;
		words.put(word, cantidad+1);
	}

	public int getOcurrences(String word) {
		Integer cantidad = words.get(word);
		if (cantidad == null) return 0;
		return cantidad;
	}

}
