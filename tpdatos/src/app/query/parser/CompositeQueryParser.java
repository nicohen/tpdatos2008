package app.query.parser;

import api.query.parser.Parser;
import api.query.tree.Query;
import app.query.parser.exception.ParserException;
import app.query.tree.CompositeQuery;

abstract public class CompositeQueryParser extends RecursiveParser {
	
	private String token;

	public CompositeQueryParser(Parser recur, String token) {
		super(recur);
		
		this.token = token; 
	}

	public Query parse(String str) throws ParserException {
		// TODO dividir la cadena por tokens, y parsear
		// recursivamente
		return null;
	}
	
	abstract public CompositeQuery createComposite() ;

}
