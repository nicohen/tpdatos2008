package test.index;

import app.dao.documents.DocumentsDictionaryImp;
import exceptions.DataAccessException;

public class TestDocumentsDictionaryImp extends TestDocumentsDictionary {

	public TestDocumentsDictionaryImp() throws DataAccessException {
		super(new DocumentsDictionaryImp() );
	}

}
