package test.index;

import api.Index;
import api.QueryEngine;
import app.bo.MockDocumentsDictionary;
import app.bo.MockIndex;

public class TestQueryEngineMocks extends TestQueryEngine {
	
	private Index index;
	
	public TestQueryEngineMocks() {
		super(
				
				new QueryEngine(
						
						new MockIndex(),
						new MockDocumentsDictionary()
						
				
					)
				
				
		
			);
		
		// TODO Auto-generated constructor stub
	}

}
