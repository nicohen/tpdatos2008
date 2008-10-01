package test.persistors;

import junit.framework.Assert;
import test.bplus.BPlusNodeTestUtils;
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
	
	@Override
	public void localAssertEquals(BPlusNode node1, BPlusNode node2) {
		BPlusNodeTestUtils.assertElementsEquals(node1.getElements(), node2.getElements() );
		Assert.assertEquals(node1.getNodeKey(), node2.getNodeKey() );
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
