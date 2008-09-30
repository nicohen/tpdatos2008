package test.index;

import api.dao.documents.DocumentsDictionary;
import app.bo.MockDocumentsDictionary;

public class TestMockDocumentsDictionary extends TestDocumentsDictionary {

	public TestMockDocumentsDictionary() {
		super(new MockDocumentsDictionary() );
	}

}
