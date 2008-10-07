package test.index;

import api.DefaultQueryEngine;
import exceptions.BusinessException;

public class TestDefaultQueryEngine extends TestQueryEngine {

	public TestDefaultQueryEngine() throws BusinessException {
		super( new DefaultQueryEngine() );
	}

}
