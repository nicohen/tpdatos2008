package test.bplus;

import java.util.HashMap;
import java.util.Map;

import junit.framework.TestCase;
import bplus.elements.BPlusLeafElement;
import bplus.keys.BPlusElementKey;


public class MapTest extends TestCase {
	private Map<String, BPlusLeafElement> map = new HashMap<String, BPlusLeafElement>();
	
	
	private void _test_insert( String str, Integer value) {
		String key = new String( str );
		String key_ = new String( str );
		map.put(key, new BPlusLeafElement(new BPlusElementKey(key),2) );
		assertEquals( value, map.get(key_).getValue() );
	}
	
	public void test() {
		//ap.put( new BPlusElementKey("prueba"), 2);
		_test_insert( "prueba",2);
	
	}

}
