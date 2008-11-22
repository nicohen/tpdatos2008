package test.query;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Iterator;

import junit.framework.TestCase;
import api.query.parser.Parser;
import api.query.tree.Query;
import app.query.QueryWord;
import app.query.parser.QueryNotParser;
import app.query.parser.QueryParser;
import app.query.parser.QueryWordParser;
import app.query.parser.exception.ParserException;
import app.query.tree.QueryAnd;
import app.query.tree.QueryNot;

public class ParserTest extends TestCase {
	private QueryParser parser ;
	
	class TestQueryWord extends QueryWord {

		public TestQueryWord(String str) {
			super(str);
		}

		public Iterator<Integer> iterator() {
			return null;
		}
		
	}
	
	class TestQueryWordParser extends QueryWordParser {

		@Override
		public QueryWord create(String word) {
			return new TestQueryWord(word);
		}
		
	}

	
	class TestQueryNot extends QueryNot {

		public TestQueryNot(Query subQuery) {
			super(subQuery);
			// TODO Auto-generated constructor stub
		}
		@Override
		public int getDocumentsCount() {
			return 0 ;
		}
		
	}
	
	class TestQueryNotParser extends QueryNotParser {

		public TestQueryNotParser(Parser recur) {
			super(recur);
		}

		@Override
		protected Query createQueryNot(Query consulta) {
			return new TestQueryNot(consulta);
		}
		
	}
		
	public ParserTest() {
		parser = new QueryParser();
		parser.addCustomParser(new TestQueryWordParser() );
		parser.addCustomParser(new TestQueryNotParser(parser) );
	}
	
	public void test() throws ParserException {
		
		QueryAnd queryAnd = new QueryAnd();
		
		queryAnd.add(new TestQueryWord("hola"));
		queryAnd.add(new TestQueryWord("mundo"));
		
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

		
		System.out.print("Ingrese consulta booleana (ingrese exit para salir): ");
		
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
		
		System.out.println();
		
		
		
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
