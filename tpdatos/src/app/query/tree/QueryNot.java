package app.query.tree;

import java.util.Iterator;

import api.query.tree.Query;

public class QueryNot implements Query {

	private Query subQuery;
	public QueryNot(Query subQuery) {
		this.subQuery = subQuery;
	}
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
