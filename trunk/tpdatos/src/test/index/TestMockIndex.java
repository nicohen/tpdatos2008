package test.index;

import exceptions.BusinessException;
import api.bo.Index;
import app.bo.MockIndex;

public class TestMockIndex extends TestIndex {

	public TestMockIndex() throws BusinessException {
		super();
	}

	@Override
	protected Index createTestObject() {
		return new MockIndex();
	}

}
