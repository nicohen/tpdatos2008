package app.query;

import java.util.Iterator;
import java.util.List;

import app.query.tree.AbstractQuery;

public abstract class QueryWord extends AbstractQuery {

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
