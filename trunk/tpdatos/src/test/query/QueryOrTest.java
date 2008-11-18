package test.query;

import app.query.tree.CompositeQuery;
import app.query.tree.QueryOr;

public class QueryOrTest extends CompositeQueryTest {

	public void test() {
		int[][] a = { {1,2,3}, {2,3,4}, {1,2,3,4} };
		_test(a);

	}

	@Override
	public CompositeQuery createComposite() {
		return new QueryOr();
	}
}
