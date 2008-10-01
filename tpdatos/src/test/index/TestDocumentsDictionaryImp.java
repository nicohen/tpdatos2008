package test.index;

import exceptions.DataAccessException;
import app.dao.documents.DocumentsDictionaryImp;

public class TestDocumentsDictionaryImp extends TestDocumentsDictionary {

	public TestDocumentsDictionaryImp() throws DataAccessException {
		super(new DocumentsDictionaryImp() );
		// TODO Auto-generated constructor stub
	}

}
