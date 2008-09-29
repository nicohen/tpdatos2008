package test.index;

import exceptions.BusinessException;
import api.bo.Index;
import app.bo.IndexImp;

public class TestIndexImp extends TestIndex {

	public TestIndexImp() throws BusinessException {
		super();
	}

	@Override
	protected Index createTestObject() throws BusinessException {
		return new IndexImp("distances.dat", 4096) ;
	}

}
