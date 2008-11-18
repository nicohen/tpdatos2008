package app.query.parser;

import api.query.parser.Parser;
import api.query.tree.Query;
import app.query.parser.exception.ParserException;

public abstract class RecursiveParser<T> implements Parser {
	
	private Parser recursive_parser = null;
	
	public void setRecursiveParser( Parser parser ) {
		this.recursive_parser = parser;
	}
	
	protected Query internalParse( String str ) throws ParserException {
		return recursive_parser.parse(str);
	}
}
