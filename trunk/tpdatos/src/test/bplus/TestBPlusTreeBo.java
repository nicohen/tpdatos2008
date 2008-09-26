package test.bplus;

import junit.framework.Assert;
import junit.framework.TestCase;
import api.bo.BPlusTree.BPlusTreeBo;
import bplus.elements.BPlusLeafElement;
import bplus.exceptions.KeyNotFoundException;
import bplus.keys.BPlusElementKey;
import exceptions.DataAccessException;


abstract public class TestBPlusTreeBo extends TestCase {

	private BPlusTreeBo bo ;

	abstract protected BPlusTreeBo createTestObject() throws DataAccessException ;
	
	public TestBPlusTreeBo() {
		try {
			bo = createTestObject();
		} catch (DataAccessException e) {
			// TODO ver q hacer con el puntero nulo
			e.printStackTrace();
		}
	}
	
	public void _test_insert( String word, Integer value) throws KeyNotFoundException, DataAccessException {
		
		BPlusElementKey key = new BPlusElementKey(word);
		bo.insertElement( new BPlusLeafElement( key , value) );

		BPlusElementKey key_ = new BPlusElementKey(word);
		Assert.assertEquals(value , bo.getElement( key_ ).getValue() );
	}

/*	public void _test_update( String word, Integer value) throws KeyNotFoundException {
		
		BPlusElementKey key = new BPlusElementKey(word);
		bo.updateElement( new BPlusLeafElement( key , value) );

		BPlusElementKey key_ = new BPlusElementKey(word);
		Assert.assertEquals(value , bo.getElement( key_ ).getValue() );
	}*/
	
	
	public void test() throws KeyNotFoundException, DataAccessException {
		
		//bo.insertElement( new BPlusLeafElement( new BPlusElement) );
		_test_insert( "bplus", 2);
		_test_insert( "b9999", 9999);
		_test_insert( "documentos", 254);
		_test_insert( "laruta", 1000);
		_test_insert( "parseaste", 34);
		
	}

}
