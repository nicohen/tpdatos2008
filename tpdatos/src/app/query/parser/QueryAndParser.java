package app.query.parser;

import api.query.parser.Parser;
import app.query.tree.CompositeQuery;
import app.query.tree.QueryAnd;

public class QueryAndParser extends CompositeQueryParser {

	public QueryAndParser(Parser recur) {
		super(recur,"and");
	}

	@Override
	public CompositeQuery createComposite() {
		return new QueryAnd();
	}

}
