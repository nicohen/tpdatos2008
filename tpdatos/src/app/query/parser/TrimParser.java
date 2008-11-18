package app.query.parser;

import api.query.tree.Query;
import app.query.parser.exception.CantDigestException;
import app.query.parser.exception.ParserException;

public class TrimParser extends RecursiveParser {

	public Query parse(String str) throws ParserException {
		
		if (str.trim ().equals(str )) {
			// si el trim de la cadena es igual, entonces
			// no puedo digerir esto
			throw new CantDigestException();
		} else {
			
			return this.internalParse(str.trim() );
		}
	}

}
