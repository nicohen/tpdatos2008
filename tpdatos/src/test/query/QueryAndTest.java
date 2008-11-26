package test.query;

import app.query.tree.CompositeQuery;
import app.query.tree.QueryAnd;

public class QueryAndTest extends CompositeQueryTest {
	public void test() {
		int[][] a = { {1,2,3}, {2,3,4}, {2,3} };
		_test(a);

		int[][] b = { {1,2,3,4}, {2,3,4}, {2,3,4} };
		_test(b);

		int[][] c = { {1,6,7}, {2,3,4,5,6,7,8}, {6,7} };
		_test(c);
		
		int[][] d = { {1,20,30}, {2,4}, {} };
		_test(d);
		
	}

	@Override
	public CompositeQuery createComposite() {
		return new QueryAnd();
	}
}
