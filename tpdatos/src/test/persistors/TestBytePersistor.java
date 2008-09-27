package test.persistors;

import exceptions.PersistanceException;
import api.po.persistors.Persistor;
import app.po.persistors.BytePersistor;
import junit.framework.TestCase;

public class TestBytePersistor extends TestPersistor<Byte> {

	@Override
	protected Persistor<Byte> createTestObject() {
		// TODO Auto-generated method stub
		return new BytePersistor();
	}

	public void test() throws PersistanceException {
		
		for ( byte i=-127;i<127;i++) {
			_test_object( new Byte(i) );
			
		}
	}
}
