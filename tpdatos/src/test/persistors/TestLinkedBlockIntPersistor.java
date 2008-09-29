package test.persistors;

import api.po.persistors.Persistor;
import app.po.persistors.IntegerPersistor;
import app.po.persistors.LinkedBlockPersistor;
import dto.LinkedBlockB;
import exceptions.PersistanceException;

public class TestLinkedBlockIntPersistor extends TestPersistor<LinkedBlockB<Integer>> {

	@Override
	protected Persistor<LinkedBlockB<Integer>> createTestObject() {
		// TODO Auto-generated method stub
		return new LinkedBlockPersistor<Integer>(new IntegerPersistor());
	}

	public void test() throws PersistanceException	{
	
		LinkedBlockB<Integer> linked1;
		linked1 = new LinkedBlockB<Integer>();
		linked1.setElem(9);
		linked1.setNextBlock(18);
		_test_object(linked1);
		
	}
}
