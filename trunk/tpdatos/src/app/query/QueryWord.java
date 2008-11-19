package app.query;

import java.util.Iterator;

import app.query.tree.AbstractQuery;

public class QueryWord extends AbstractQuery {

	private String word;
	
	public QueryWord( String str ) {
		this.word = str; 
	}
	
	public Iterator<Integer> execute() {
		// TODO Auto-generated method stub
		return null;
	}

	public void dump(int ntabs) {
		for (int i=0;i<ntabs;i++) System.out.print("\t");
		System.out.println("Word:"+word);
	}

}