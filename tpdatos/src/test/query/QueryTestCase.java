package test.query;

import java.util.Iterator;

import junit.framework.TestCase;

public class QueryTestCase extends TestCase {
	public void assertResultSet( Iterator<Integer> result1, int[] result2 ) {
		int i = 0;
			
		while (result1.hasNext() ) {
			
			assertEquals(result2[i], result1.next().intValue() );
			i++;
		}

		if (result2.length > i) {
			assertTrue(false);
		}
		// si result1 tiene mas elementos de los que deberia...
		if (result1.hasNext() ) {
			assertTrue(false);
		}
	}

}
