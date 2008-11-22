package app.query.tree;

import java.util.Iterator;
import java.util.List;

import api.query.tree.Query;

public abstract class QueryNot implements Query {

	private Query subQuery;
	public QueryNot(Query subQuery) {
		this.subQuery = subQuery;
	}
	abstract public int getDocumentsCount();		
	
	public Iterator<Integer> iterator() {
		// TODO
		
		return null;
	}
	@Override
	public void dump(int ntabs) {
		for (int i=0;i<ntabs;i++) System.out.print("\t");
		System.out.println("not ");
		this.subQuery.dump(ntabs+1);
	}
}
