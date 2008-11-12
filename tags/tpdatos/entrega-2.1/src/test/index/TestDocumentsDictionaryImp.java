package test.index;

import app.dao.documents.DocumentsDictionaryImp;
import exceptions.DataAccessException;

public class TestDocumentsDictionaryImp extends TestDocumentsDictionary {

	public TestDocumentsDictionaryImp() throws DataAccessException {
		super(new DocumentsDictionaryImp("indexed_documents.bin","document_names.txt") );
		// TODO Auto-generated constructor stub
	}

}
