package test.persistors;

import exceptions.PersistanceException;
import api.po.persistors.Persistor;
import app.po.persistors.StringPersistor;

public class TestStringPersistor extends TestPersistor<String>{

	@Override
	protected Persistor<String> createTestObject() {
		// TODO Auto-generated method stub
		return new StringPersistor(256);
	}
	
	
	public void test() throws PersistanceException {
		_test_object("");
		_test_object("a");
		_test_object("b");
		_test_object("persistor");
	}

}
