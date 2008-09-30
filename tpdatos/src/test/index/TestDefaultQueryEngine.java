package test.index;

import api.DefaultQueryEngine;
import exceptions.BusinessException;

public class TestDefaultQueryEngine extends TestQueryEngine {

	protected TestDefaultQueryEngine() throws BusinessException {
		super( new DefaultQueryEngine() );
	}

}
