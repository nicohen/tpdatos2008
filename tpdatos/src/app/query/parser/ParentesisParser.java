package app.query.parser;

import api.query.parser.Parser;
import api.query.tree.Query;
import app.query.parser.exception.CantDigestException;
import app.query.parser.exception.ParserException;

public class ParentesisParser extends RecursiveParser {

	public ParentesisParser(Parser recur) {
		super(recur);
	}

	public Query parse(String str) throws ParserException {
		if (str.charAt(0) == '(' && str.charAt(str.length()-1 ) == ')' ){
			String substr = str.substring(1, str.length()-1 ); 
			return this.internalParse(substr);
		}
		throw new CantDigestException();
	}

}
