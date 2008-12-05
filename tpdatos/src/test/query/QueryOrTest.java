package test.query;

import app.query.tree.CompositeQuery;
import app.query.tree.QueryOr;

public class QueryOrTest extends CompositeQueryTest {

	public void test() {
		int[][] a = { {1,2,3}, {2,3,4}, {1,2,3,4} };
		_test(a);

		int[][] a_ = { {1,2,3}, {8,9,10}, {1,2,3,8,9,10} };
		_test(a_);

		int[][] b = { {1,2,3}, {4,5,6}, {1,2,3,4,5,6} };
		_test(b);
		
		int[][] c = { {1,2,3}, {3,4,5,6}, {1,2,3,4,5,6} };
		_test(c);

		int[][] d = { {1,2,3,4}, {3,4,5,6}, {1,2,3,4,5,6} };
		_test(d);

		int[][] e = { {1,2,3,4}, {1,2,3,4}, {1,2,3,4} };
		_test(e);

	}

	@Override
	public CompositeQuery createComposite() {
		return new QueryOr();
	}
}
