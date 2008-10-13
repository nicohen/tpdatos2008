package test.index;

import api.Index;
import app.bo.IndexImpB;
import exceptions.BusinessException;

public class TestIndexImpB extends TestIndex {

	public TestIndexImpB() throws BusinessException {
		super();
	}

	@Override
	protected Index createTestObject() throws BusinessException {
		return new IndexImpB("test-index-b.bin",4096);
	}

}
