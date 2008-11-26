package test.query;

import app.query.tree.CompositeQuery;

public abstract class CompositeQueryTest extends QueryTestCase {
	
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
		
		query.add(mock1);
		query.add(mock2);
		
		this.assertResultSet(query.iterator() , expected );
	}

	
	public abstract CompositeQuery createComposite() ;
}
