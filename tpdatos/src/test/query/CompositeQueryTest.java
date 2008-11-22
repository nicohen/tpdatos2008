package test.query;

import java.util.Iterator;

import junit.framework.TestCase;
import app.query.tree.CompositeQuery;

public abstract class CompositeQueryTest extends TestCase {
	
	void _test( int[][] a) {
		// construir la query
		
		int[] result1 = a[0];
		int[] result2 = a[1];
		int[] expected = a[2];
		
		CompositeQuery query = createComposite();
		MockQuery mock1 = new MockQuery();
		MockQuery mock2 = new MockQuery();

		for (int i=0; i<result1.length; i++) {
			mock1.add( new Integer( result1[i] ) );
		}
		for (int i=0; i<result2.length; i++) {
			mock2.add( new Integer( result1[i] ) );
		}
		
		this.assertResultSet(query.iterator() , expected );
	}

	public void assertResultSet( Iterator<Integer> result1, int[] result2 ) {
		int i = 0;
			
		while (result1.hasNext() ) {
			assertEquals(result1.next().intValue(), result2[i] );
			i++;
		}

		// si result1 tiene mas elementos de los que deberia...
		if (result1.hasNext() ) {
			assertTrue(false);
		}
	}
	
	public abstract CompositeQuery createComposite() ;
}
