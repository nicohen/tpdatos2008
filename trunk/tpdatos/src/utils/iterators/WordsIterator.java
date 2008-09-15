package utils.iterators;

import java.util.Iterator;

import dto.WordDto;

public class WordsIterator implements Iterator<WordDto> {

	protected String document = null;
	
	public WordsIterator(String document) {
		this.document = document;
	}
	
	@Override
	public boolean hasNext() {
		return false;
	}

	@Override
	public WordDto next() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void remove() {
		// TODO Auto-generated method stub
		
	}

}
