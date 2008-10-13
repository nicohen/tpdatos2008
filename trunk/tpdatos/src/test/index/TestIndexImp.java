package test.index;

import app.bo.IndexImp;
import exceptions.BusinessException;

public class TestIndexImp extends TestIndex {

	public TestIndexImp() throws BusinessException {
		//super();
	}

	@Override
	protected IndexImp createTestObject() throws BusinessException {
		return new IndexImp("test-index.bin", 4096) ;
	}


}
