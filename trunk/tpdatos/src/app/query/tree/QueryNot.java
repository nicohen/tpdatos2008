package app.query.tree;

import java.util.Iterator;

import api.query.tree.Query;

public class QueryNot implements Query {

	public QueryNot(Query subQuery) {
		// TODO Auto-generated constructor stub
	}
	public Iterator<Integer> iterator() {
		// TODO
		return null;
	}
	@Override
	public void dump(int ntabs) {
		for (int i=0;i<ntabs;i++) System.out.print("\t");
		System.out.println("not ");
	}
}
