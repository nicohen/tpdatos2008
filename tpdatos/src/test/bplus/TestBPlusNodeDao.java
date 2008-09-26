package test.bplus;

import org.junit.Assert;
import api.dao.BPlusTree.BPlusNodeDao;
import bplus.exceptions.NodeOverflowException;
import bplus.keys.BPlusNodeKey;
import bplus.nodes.BPlusLeafNode;
import bplus.nodes.BPlusNode;
import exceptions.DataAccessException;
import junit.framework.TestCase;

// Este test generico testea todas las implementaciones
// de BPlusNodeDao, es un ABSTRACT FACTORY que se abstrae
// de la instancia de implementacion de BPlusNodeDato
// que construye para testear


abstract public class TestBPlusNodeDao extends TestCase {
	
	private BPlusNodeDao dao ;
	
	abstract protected BPlusNodeDao createTestObject() throws DataAccessException;
	
	public TestBPlusNodeDao() {
		try {
			dao = createTestObject();
		} catch (DataAccessException e) {
			// TODO evitar el null pointer y dejar un error mas claro
			e.printStackTrace();
		}
	}

	public BPlusNode _test_insert(BPlusNode node) throws DataAccessException{
		BPlusNodeKey key = dao.insertNode(node);

		BPlusNode nodoInsertado = dao.getNode(key);
		
		Assert.assertTrue ( nodoInsertado.equals(node) );
		
		return nodoInsertado;
		
	}

	public void _test_update(BPlusNode node) throws DataAccessException, NodeOverflowException{
		//BPlusNodeKey key = dao.insertNode(node);
		
		dao.updateNode(node);

		BPlusNode nodoInsertado = dao.getNode(node.getNodeKey() );
		
		Assert.assertTrue ( nodoInsertado.equals(node) );
		
	}
	
	
	public void test() throws DataAccessException, NodeOverflowException {
		
		
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
