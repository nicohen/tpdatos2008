package test.index;

import api.Index;
import api.QueryEngine;
import api.dao.documents.DocumentsDictionary;
import app.bo.IndexImp;
import app.bo.MockDocumentsDictionary;
import app.bo.MockIndex;
import app.dao.documents.DocumentsDictionaryImp;
import exceptions.BusinessException;
import exceptions.DataAccessException;

public class TestInsertQueryEngine extends TestQueryEngine {
	
	private Index index;
	
	protected TestInsertQueryEngine() {
		super(
				
				new QueryEngine(
						
						new MockIndex(),
						new MockDocumentsDictionary()
						
				
					)
				
				
		
			);
		
		// TODO Auto-generated constructor stub
	}

}
