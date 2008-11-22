package app.query;

import api.query.tree.Query;

public abstract class QueryWord implements Query {

	private String word;
	
	public QueryWord( String str ) {
		this.word = str; 
	}
	
	public void dump(int ntabs) {
		for (int i=0;i<ntabs;i++) System.out.print("\t");
		System.out.println("Word:"+word);
	}
	
	public String getWord() {
		return word;
	}

}
