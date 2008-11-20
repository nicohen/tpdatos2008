package test.index;

import utils.Constants;
import api.DefaultQueryEngine;
import exceptions.BusinessException;
import exceptions.DataAccessException;

public class TestDefaultQueryEngine extends TestQueryEngine {

	public TestDefaultQueryEngine() throws BusinessException, DataAccessException {
		super( new DefaultQueryEngine(Constants.BPLUS_FILE_SIZE) );
	}

}
