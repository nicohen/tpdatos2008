package app.query.parser;

import api.query.parser.Parser;
import app.query.tree.CompositeQuery;
import app.query.tree.QueryOr;

public class QueryOrParser extends CompositeQueryParser {

	public QueryOrParser(Parser recur) {
		super(recur, "or");
	}

	@Override
	public CompositeQuery createComposite() {
		return new QueryOr();
	}

}
