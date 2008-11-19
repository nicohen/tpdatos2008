package app.query.tree;

import java.util.Iterator;

public class QueryAnd extends CompositeQuery {

	public Iterator<Integer> execute() {
		// TODO
		return null;
	}

	@Override
	String operatorName() {
		return "and";
	}


}
