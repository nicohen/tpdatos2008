package test.bplus;


import junit.framework.TestCase;

import org.junit.Assert;
import org.junit.Before;

import exceptions.DataAccessException;

import bplus.keys.BPlusNodeKey;
import bplus.nodes.BPlusLeafNode;
import bplus.nodes.BPlusNode;

import app.dao.bplus.BPlusNodeDaoTest;

public class BPlusNodeDaoTestTest extends TestCase {
	
	
	private BPlusNodeDaoTest dao = new BPlusNodeDaoTest();

	@Before
	public void setUp() throws Exception {
	}

	public Integer _test_insert(BPlusNode node) throws DataAccessException{
		BPlusNodeKey key = dao.insertNode(node);

		BPlusNode nodoInsertado = dao.getNode(key);
		
		this.assertTrue ( nodoInsertado.equals(node) );
		
		return key.getValue();
		
	}
	
	public void test() throws DataAccessException {
		
		BPlusNode node = new BPlusLeafNode();
		_test_insert(node);
	}
	
}
