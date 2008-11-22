package app.query.parser;

import api.query.parser.Parser;
import api.query.tree.Query;
import app.query.parser.exception.CantDigestException;
import app.query.parser.exception.ParserException;
import app.query.tree.QueryNot;

public class QueryNotParser extends RecursiveParser {

	public QueryNotParser(Parser recur) {
		super(recur);
	}

	@Override
	public Query parse(String str) throws ParserException {
		// TODO Auto-generated method stub
		if (! str.substring(0, 3).equals("not") ) {
			throw new CantDigestException();
		}
		
		String substr = str.substring(5);
		Query subQuery = this.internalParse(substr);
		
		return new QueryNot(subQuery);
	}
	
}
