package test.query;

import app.query.QueryWord;
import app.query.parser.QueryParser;
import app.query.tree.QueryAnd;
import junit.framework.TestCase;

public class ParserTest extends TestCase {
	public void test() {
		
		QueryAnd queryAnd = new QueryAnd();
		
		queryAnd.add(new QueryWord("hola"));
		queryAnd.add(new QueryWord("mundo"));
		
		// salida esperada:
		// and
		//		Word: hola
		//		Word: mundo
		
		queryAnd.dump(0);
		
		//QueryParser parser = new QueryParser();
		
		
	}
}
