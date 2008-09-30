package test.index;

import api.DocumentsDictionary;
import app.bo.MockDocumentsDictionary;

public class TestMockDocumentsDictionary extends TestDocumentsDictionary {

	public TestMockDocumentsDictionary() {
		super(new MockDocumentsDictionary() );
	}

}
