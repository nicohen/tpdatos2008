package test.bplus;

import bplus.elements.BPlusLeafElement;
import bplus.exceptions.KeyNotFoundException;
import bplus.keys.BPlusElementKey;
import app.bo.bplus.BPlusTreeBoTest;
import junit.framework.Assert;
import junit.framework.TestCase;


// prueba la funcinalidad del BPlusTreeBoTest

public class BPlusTreeBoTestTest extends TestCase {

	
	private BPlusTreeBoTest bo = new BPlusTreeBoTest();
	
	public void _test_insert( String word, Integer value) throws KeyNotFoundException {
		
		BPlusElementKey key = new BPlusElementKey(word);
		bo.insertElement( new BPlusLeafElement( key , value) );

		BPlusElementKey key_ = new BPlusElementKey(word);
		Assert.assertEquals(value , bo.getElement( key_ ).getValue() );
	}

	public void _test_update( String word, Integer value) throws KeyNotFoundException {
		
		BPlusElementKey key = new BPlusElementKey(word);
		bo.updateElement( new BPlusLeafElement( key , value) );

		BPlusElementKey key_ = new BPlusElementKey(word);
		Assert.assertEquals(value , bo.getElement( key_ ).getValue() );
	}
	
	
	public void test() throws KeyNotFoundException {
		
		//bo.insertElement( new BPlusLeafElement( new BPlusElement) );
		_test_insert( "bplus", 2);
		_test_insert( "b9999", 9999);
		_test_insert( "documentos", 254);
		_test_insert( "laruta", 1000);
		_test_insert( "parseaste", 34);
		
		_test_update( "bplus", 90);
		_test_update( "b9999", 8888);
		_test_update( "documentos", 892);
	}
}