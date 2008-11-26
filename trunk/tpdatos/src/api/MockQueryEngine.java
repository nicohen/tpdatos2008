package api;

import app.bo.MockDocumentsDictionary;
import app.bo.MockIndex;

public class MockQueryEngine extends QueryEngine {

	public MockQueryEngine() {
		super( new MockIndex(), new MockDocumentsDictionary(),"" );
	}

}
