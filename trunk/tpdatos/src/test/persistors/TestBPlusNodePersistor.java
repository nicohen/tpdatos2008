package test.persistors;

import api.po.persistors.Persistor;
import app.po.persistors.BPlusNodePersistor;
import bplus.elements.BPlusLeafElement;
import bplus.keys.BPlusElementKey;
import bplus.nodes.BPlusLeafNode;
import bplus.nodes.BPlusNode;
import exceptions.PersistanceException;

public class TestBPlusNodePersistor extends TestPersistor<BPlusNode>{

	@Override
	protected Persistor<BPlusNode> createTestObject() {
		// TODO Auto-generated method stub
		return new BPlusNodePersistor(4096);
	}
	
	public void test() throws PersistanceException {
		BPlusNode node = new BPlusLeafNode();
		
		_test_object(node);
		
		BPlusElementKey key1 = new BPlusElementKey("key1");
		BPlusElementKey key2 = new BPlusElementKey("key2");
		BPlusElementKey key3 = new BPlusElementKey("key3");
		BPlusElementKey key4 = new BPlusElementKey("key4");

		BPlusLeafElement element = new BPlusLeafElement(key1, 1);
		
		node.insertElement(element);
		_test_object(node);

		element = new BPlusLeafElement(key2, 1);
		
		node.insertElement(element);
		_test_object(node);

		element = new BPlusLeafElement(key3, 50);

		node.insertElement(element);
		_test_object(node);
		
		element = new BPlusLeafElement(key4, 3);
		
		node.insertElement(element);
		_test_object(node);

	}

}
