package test.query;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import api.query.tree.Query;
import app.query.QueryWord;
import app.query.parser.QueryParser;
import app.query.parser.QueryWordParser;
import app.query.parser.exception.ParserException;
import app.query.tree.QueryAnd;
import junit.framework.TestCase;

public class ParserTest extends TestCase {
	private QueryParser parser ;
	
	class TestQueryWord extends QueryWord {

		public TestQueryWord(String str) {
			super(str);
		}
		
	}
	
	class TestQueryWordParser extends QueryWordParser {

		@Override
		public QueryWord create(String word) {
			return new TestQueryWord(word);
		}
		
	}
	
	public ParserTest() {
		parser = new QueryParser();
		parser.addCustomParser(new TestQueryWordParser() );
	}
	
	public void test() throws ParserException {
		
		QueryAnd queryAnd = new QueryAnd();
		
		queryAnd.add(new QueryWord("hola"));
		queryAnd.add(new QueryWord("mundo"));
		
		// salida esperada:
		// and
		//		Word: hola
		//		Word: mundo
		
		queryAnd.dump(0);
		
		parser.parse("hola and mundo").dump(0);
		
		// esa query deberia deovolver el mismo resultado que el anterior
		
		parser.parse("hola or mundo").dump(0);
		
		// ahora lo mismo pero con el operador or

		// evidentemente, las siguientes dos querys deben devolver
		// resultados diferentes
		
		parser.parse("hola and (como or estan)").dump(0);
		
		parser.parse("(hola and como)or estan").dump(0);

	}
	
	class ExitException extends Exception {

		/**
		 * 
		 */
		private static final long serialVersionUID = 1L;
	}
	
	private void processLine () throws IOException, ExitException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String strquery = br.readLine();

		if (strquery.equals("exit") ) {
			throw new ExitException();
		}

		try {
			Query query = parser.parse(strquery);
			query.dump(0);
		} catch (ParserException e) {
			System.out.println("Error en el parseo, sintaxis invalida");
	
		}
		
		
		
	}
	
	public void interactiveTest() throws IOException {
		try {
			while(true){
					processLine();
			}
		} catch (ExitException e) {
		}
	}
}
