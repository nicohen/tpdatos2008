package test.query;

import api.query.tree.Query;
import app.query.tree.QueryNot;
import junit.framework.TestCase;

public class QueryNotTest extends QueryTestCase {
	private class QueryNotTested extends QueryNot {

		public QueryNotTested(Query subQuery) {
			super(subQuery);
			// TODO Auto-generated constructor stub
		}

		@Override
		public int getDocumentsCount() {
			return 16;
		}
		
	}
	
	public void _test_not( int[][] a ) {
		
		int[] result1 = a[0];
		int[] expected = a[1];
		
		MockQuery mock1 = new MockQuery();

		for (int i=0; i<result1.length; i++) {
			mock1.add( new Integer( result1[i] ) );
		}
		
		Query query = new QueryNotTested( mock1 );
		
		assertResultSet( query.iterator(), expected );
	}
	
	public void test() {
		int[][] a = { {1,2 }, {0,3,4,5,6,7,8,9,10,11,12,13,14,15 } };
		_test_not(a);

		int[][] b = { {2,3,9,10 }, {0,1,4,5,6,7,8,11,12,13,14,15 } };
		_test_not(b);

		int[][] c = { {4,5,7 }, {0,1,2,3,6,8,9,10,11,12,13,14,15 } };
		_test_not(c);
	}
}
