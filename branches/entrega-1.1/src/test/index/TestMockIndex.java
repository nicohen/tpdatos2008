package test.index;

import api.Index;
import app.bo.MockIndex;
import exceptions.BusinessException;

public class TestMockIndex extends TestIndex {

	public TestMockIndex() throws BusinessException {
		super();
	}

	@Override
	protected Index createTestObject() {
		return new MockIndex();
	}

}
