package app.query;

import java.util.Iterator;

import dto.WordDto;

import api.query.tree.Query;

public class QueryWord implements Query {

	private WordDto word;
	
	public QueryWord( WordDto dto ) {
		this.word = dto; 
	}
	
	public Iterator<Integer> execute() {
		// TODO Auto-generated method stub
		return null;
	}

}
