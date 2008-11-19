package app.query.parser;

import java.util.LinkedList;
import java.util.List;

import api.query.parser.Parser;
import api.query.tree.Query;
import app.query.parser.exception.CantDigestException;
import app.query.parser.exception.ParserException;
import app.query.tree.CompositeQuery;

abstract public class CompositeQueryParser extends RecursiveParser {
	
	private String separator;

	public CompositeQueryParser(Parser recur, String separator) {
		super(recur);
		
		this.separator = separator; 
	}

	public Query parse(String str) throws ParserException {
		// TODO dividir la cadena por tokens, y parsear
		// recursivamente

		List<String> tokens = new LinkedList<String>();
		
		for (int i=1; i<str.length()-separator.length()-1; i++) {
			
			// TODO: ignorar el separator si esta entre parentesis
			
			// si el substring tiene el token
			if (str.substring(i,i+separator.length() ).equals(separator) ) {
				// y si ademas , esta rodeado por espacios
				if (str.charAt(i-1)==' ' && str.charAt(i+separator.length()+1)==' ') {
					// agregar los dos tokens y salir
					
					String newtoken;
					
					newtoken = str.substring(0,i-1);
					tokens.add(newtoken);
					
					newtoken = str.substring(i+separator.length()+1,str.length());
					tokens.add(newtoken);
					
					break;
				}
			}
		}
		
		if (tokens.size() < 2  ) {
			// este parser no puede parsear algo de menos de dos tokens
			throw new CantDigestException();
		}
		
		CompositeQuery query = createComposite();
		
		for (String token : tokens ) {
			// agregar a la query compuesta la query resultante
			// de parsear cada token
			query.add( this.internalParse(token) );
		}
		
		return query;
	}
	
	abstract public CompositeQuery createComposite() ;

}
