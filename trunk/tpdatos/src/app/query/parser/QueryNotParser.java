package app.query.parser;

import api.query.parser.Parser;
import api.query.tree.Query;
import app.query.parser.exception.CantDigestException;
import app.query.parser.exception.ParserException;

public abstract class QueryNotParser extends RecursiveParser {

	public QueryNotParser(Parser recur) {
		super(recur);
	}
	abstract protected Query createQueryNot(Query consulta);
	@Override
	public Query parse(String str) throws ParserException {
		if (str.length() < 4) {
			throw new CantDigestException();
		}
		if (! str.substring(0, 3).equals("not") ) {
			throw new CantDigestException();
		}
		
		String substr = str.substring(4);
		Query subQuery = this.internalParse(substr);
		
		return createQueryNot(subQuery);
	}
	
}
