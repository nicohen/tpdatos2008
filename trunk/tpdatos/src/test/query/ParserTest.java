package test.query;

import app.query.QueryWord;
import app.query.parser.QueryParser;
import app.query.parser.exception.ParserException;
import app.query.tree.QueryAnd;
import junit.framework.TestCase;

public class ParserTest extends TestCase {
	public void test() throws ParserException {
		
		QueryAnd queryAnd = new QueryAnd();
		
		queryAnd.add(new QueryWord("hola"));
		queryAnd.add(new QueryWord("mundo"));
		
		// salida esperada:
		// and
		//		Word: hola
		//		Word: mundo
		
		queryAnd.dump(0);
		
		QueryParser parser = new QueryParser();
		
		parser.parse("hola and mundo").dump(0);
		
		// esa query deberia deovolver el mismo resultado que el anterior
		
		parser.parse("hola or mundo").dump(0);
		
		// ahora lo mismo pero con el operador or

		// evidentemente, las siguientes dos querys deben devolver
		// resultados diferentes
		
		parser.parse("hola and (como or estan)").dump(0);
		
		parser.parse("(hola and como) or estan").dump(0);

	}
}
