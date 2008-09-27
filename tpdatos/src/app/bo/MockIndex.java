package app.bo;

import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import exceptions.BusinessException;

import api.bo.Index;

public class MockIndex implements Index {

	private Map<String,List<Integer> > map = new HashMap<String,List<Integer> >();
	
	@Override
	public Iterator<Integer> getDocuments(String word) throws BusinessException {
		
		try {
			return map.get(word).iterator();
		} catch ( NullPointerException e ) {
			throw new BusinessException();
		}
	}

	@Override
	public void insertWord(String word, Integer documento) {
		addEntry(word);
		map.get(word).add(documento);
		
	}
	
	private void addEntry(String word ) {
		if (map.get(word)==null) {
			map.put(word, new LinkedList<Integer>() );
		}
	}

}
