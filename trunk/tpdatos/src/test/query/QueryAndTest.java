package test.query;

import app.query.tree.CompositeQuery;
import app.query.tree.QueryAnd;

public class QueryAndTest extends CompositeQueryTest {
	public void test() {
		int[][] a = { {1,2,3}, {2,3,4}, {2,3} };
		_test(a);

	}

	@Override
	public CompositeQuery createComposite() {
		return new QueryAnd();
	}
}
