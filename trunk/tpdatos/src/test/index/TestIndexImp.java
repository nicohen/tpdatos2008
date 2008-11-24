package test.index;

import utils.Constants;
import app.bo.IndexImp;
import exceptions.BusinessException;

public class TestIndexImp extends TestIndex {

	public TestIndexImp() throws BusinessException {
		//super();
	}

	@Override
	protected IndexImp createTestObject() throws BusinessException {
		return new IndexImp("","index.bin", 4096,Constants.BPLUS_FILE_SIZE) ;
	}


}
