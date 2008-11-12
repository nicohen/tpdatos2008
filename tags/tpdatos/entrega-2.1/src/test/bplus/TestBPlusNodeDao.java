package test.bplus;

import junit.framework.TestCase;

import org.junit.Assert;

import api.dao.BPlusTree.BPlusNodeDao;
import bplus.exceptions.NodeOverflowException;
import bplus.keys.BPlusNodeKey;
import bplus.nodes.BPlusIndexNode;
import bplus.nodes.BPlusLeafNode;
import bplus.nodes.BPlusNode;
import exceptions.DataAccessException;

// Este test generico testea todas las implementaciones
// de BPlusNodeDao, es un ABSTRACT FACTORY que se abstrae
// de la instancia de implementacion de BPlusNodeDato
// que construye para testear


abstract public class TestBPlusNodeDao extends TestCase {
	
	private BPlusNodeDao dao ;
	
	abstract protected BPlusNodeDao createTestObject() throws DataAccessException;
	
	public TestBPlusNodeDao() throws DataAccessException {
		dao = createTestObject();
	}

	public BPlusNode _test_insert(BPlusNode node) throws DataAccessException, NodeOverflowException{
		BPlusNodeKey key = dao.insertNode(node);

		BPlusNode nodoInsertado = dao.getNode(key);
		
		Assert.assertEquals ( nodoInsertado, node );
		BPlusNodeTestUtils.assertElementsEquals(nodoInsertado.getElements(), node.getElements() );
		
		return nodoInsertado;
		
	}

	public void _test_update(BPlusNode node) throws DataAccessException, NodeOverflowException{
		//BPlusNodeKey key = dao.insertNode(node);
		
		dao.updateNode(node);

		BPlusNode nodoInsertado = dao.getNode(node.getNodeKey() );
		
		Assert.assertTrue ( nodoInsertado.equals(node) );
		
	}
	
	public void _test_root(BPlusNode node) throws DataAccessException {
		dao.setRootNode(node.getNodeKey());
		BPlusNode nodoInsertado = dao.getRootNode();
		Assert.assertTrue( nodoInsertado.equals(node));
	}
	
	
	public void test() throws DataAccessException, NodeOverflowException {
		
		
		// TODO: probar distintos nodos , con diferente contenido, etc...
		
		BPlusNode nodeL = new BPlusLeafNode();
		BPlusNode nodeI = new BPlusIndexNode();
		
		BPlusNode node1 = _test_insert(nodeL);
		BPlusNode node2 = _test_insert(nodeI);
		BPlusNode node3 = _test_insert(nodeL);
		BPlusNode node4 = _test_insert(nodeI);
		
		_test_update( node1 );
		_test_update( node2 );
		_test_update( node3 );
		_test_update( node4 );
		
		_test_root(node1);
		_test_root(node2);
		_test_root(node3);
		_test_root(node4);
		
	}

}
