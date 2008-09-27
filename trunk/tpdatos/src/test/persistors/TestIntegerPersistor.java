package test.persistors;

import api.po.persistors.Persistor;
import app.po.persistors.IntegerPersistor;
import exceptions.PersistanceException;

public class TestIntegerPersistor extends TestPersistor<Integer> {

	@Override
	protected Persistor<Integer> createTestObject() {
		// TODO Auto-generated method stub
		return new IntegerPersistor();
	}
	
	
	public void test() throws PersistanceException {
		for (int i = 0; i < 65535; i+=6) {
			_test_object(new Integer(i));
		}
	}

}
