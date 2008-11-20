package app.query.parser;

import api.query.parser.Parser;
import api.query.tree.Query;
import app.query.QueryWord;
import app.query.parser.exception.ParserException;
import app.query.parser.exception.CantDigestException;

abstract public class QueryWordParser implements Parser {

	public Query parse(String str) throws ParserException {
		
		if (str.equals("") ) throw new CantDigestException();
		// todo es un word, para este parser
		return create(str);
	}
	
	abstract public QueryWord create(String word); 

}
