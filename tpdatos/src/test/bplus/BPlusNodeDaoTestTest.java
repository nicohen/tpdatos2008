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

	public BPlusNode _test_insert(BPlusNode node) throws DataAccessException{
		BPlusNodeKey key = dao.insertNode(node);

		BPlusNode nodoInsertado = dao.getNode(key);
		
		Assert.assertTrue ( nodoInsertado.equals(node) );
		
		return nodoInsertado;
		
	}

	public void _test_update(BPlusNode node) throws DataAccessException{
		//BPlusNodeKey key = dao.insertNode(node);
		
		dao.updateNode(node);

		BPlusNode nodoInsertado = dao.getNode(node.getNodeKey() );
		
		Assert.assertTrue ( nodoInsertado.equals(node) );
		
	}
	
	
	public void test() throws DataAccessException {
		
		
		// TODO: probar distintos nodos , con diferente contenido, etc...
		
		BPlusNode node = new BPlusLeafNode(new BPlusNodeKey(0) );
		
		BPlusNode node1 = _test_insert(node);
		BPlusNode node2 = _test_insert(node);
		BPlusNode node3 = _test_insert(node);
		
		_test_update( node1 );
		_test_update( node2 );
		_test_update( node3 );
		
	}
	
}
