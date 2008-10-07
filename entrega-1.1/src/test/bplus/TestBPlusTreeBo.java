package test.bplus;

import junit.framework.Assert;
import junit.framework.TestCase;
import api.bo.BPlusTree.BPlusTreeBo;
import bplus.elements.BPlusLeafElement;
import bplus.exceptions.KeyNotFoundException;
import bplus.keys.BPlusElementKey;
import exceptions.DataAccessException;


abstract public class TestBPlusTreeBo extends TestCase {

	protected BPlusTreeBo bo ;

	abstract protected BPlusTreeBo createTestObject() throws DataAccessException ;
	
	public TestBPlusTreeBo() throws DataAccessException {
		bo = createTestObject();
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
		this.bo.dump();
		System.out.println("--------------------------------------------------------");
		_test_insert( "b9999", 9999);
		this.bo.dump();
		System.out.println("--------------------------------------------------------");
		_test_insert( "parseaste", 34);
		this.bo.dump();
		System.out.println("--------------------------------------------------------");
		_test_insert( "documentos", 254);
		this.bo.dump();
		System.out.println("--------------------------------------------------------");
		_test_insert( "laruta", 1000);
		this.bo.dump();
		System.out.println("--------------------------------------------------------");
		_test_insert( "perro", 1000);
		this.bo.dump();
		System.out.println("--------------------------------------------------------");
		_test_insert( "gato", 1200);
		this.bo.dump();
		System.out.println("--------------------------------------------------------");
		_test_insert( "gatiperro", 3);
		this.bo.dump();
	}

}
