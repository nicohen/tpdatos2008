package app.query.parser;

import api.query.tree.Query;
import app.query.parser.exception.ParserException;

public class QueryParser extends CompositeParser {

	public QueryParser() {
		this.add(new QueryWordParser() );
	}
	
	public Query parse(String str) throws ParserException {
		return null;
	}

}
