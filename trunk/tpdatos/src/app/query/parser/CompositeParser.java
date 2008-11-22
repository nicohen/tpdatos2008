package app.query.parser;

import java.util.ArrayList;
import java.util.List;

import api.query.parser.Parser;
import api.query.tree.Query;
import app.query.parser.exception.CantDigestException;
import app.query.parser.exception.ParserException;

public class CompositeParser implements Parser {

	private List<Parser > lista = new ArrayList<Parser>() ;
	
	public Query parse(String str) throws ParserException {
		for ( Parser cadauno : lista ) {
			
			try {
				return cadauno.parse(str);
			} catch ( CantDigestException e ) {
				// continuar, intentando con otro parser
			}
		}
		
		throw new CantDigestException();
	}
	
	public void add ( Parser parser ) {
		lista.add(parser);
	}
	

}
