package app.query;

import java.util.Iterator;

import dto.WordDto;

import api.query.tree.Query;

public class QueryWord implements Query {

	private String word;
	
	public QueryWord( String str ) {
		this.word = str; 
	}
	
	public Iterator<Integer> execute() {
		// TODO Auto-generated method stub
		return null;
	}

}
