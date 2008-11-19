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
		
		// esta query deveria deovolver el mismo resultado que el anterior
		
		
	}
}
