package app.bo;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import api.bo.Index;
import exceptions.BusinessException;

public class MockIndex implements Index {

	private Map<String,ArrayList<Integer> > map = new HashMap<String,ArrayList<Integer> >();
	
	@Override
	public ArrayList<Integer> getDocuments(String word) throws BusinessException {
		
		try {
			return map.get(word);
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
			map.put(word, new ArrayList<Integer>() );
		}
	}

}
