package app.query.parser;

import java.util.StringTokenizer;

import api.query.parser.Parser;
import api.query.tree.Query;
import app.query.QueryWord;
import app.query.parser.exception.CantDigestException;
import app.query.parser.exception.ParserException;
import app.query.tree.QueryAnd;

abstract public class QueryWordParser implements Parser {

	public Query parse(String str) throws ParserException {
		
		// los caracteres especiales de ) y ( no son tolerados
		// en un string
		if (str.contains(")") ) throw new CantDigestException();
		if (str.contains("(") ) throw new CantDigestException();
		if (str.equals("") ) throw new CantDigestException();
		// todo es un word, para este parser
		
		// primero , partirlo en tokens por el caracter espacio
		
		StringTokenizer tokenizer = new StringTokenizer( str, " ");
		
		if (tokenizer.countTokens() <= 1) {
			return create(str);
		} else {

			QueryAnd queryAnd = new QueryAnd();
			
			while (tokenizer.hasMoreTokens()) {
				queryAnd.add( create(tokenizer.nextToken() ) );
			}
			
			return queryAnd;
		}
	}
	
	abstract public QueryWord create(String word); 

}
