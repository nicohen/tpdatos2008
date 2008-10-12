package test.index;

import api.DefaultQueryEngine;
import exceptions.BusinessException;
import exceptions.DataAccessException;

public class TestDefaultQueryEngine extends TestQueryEngine {

	public TestDefaultQueryEngine() throws BusinessException, DataAccessException {
		super( new DefaultQueryEngine() );
	}

}
