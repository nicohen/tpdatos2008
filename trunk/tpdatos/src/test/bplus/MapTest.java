package test.bplus;

import java.util.HashMap;
import java.util.Map;

import bplus.elements.BPlusLeafElement;
import bplus.keys.BPlusElementKey;
import junit.framework.Assert;
import junit.framework.TestCase;


public class MapTest extends TestCase {
	private Map<BPlusElementKey, BPlusLeafElement> map = new HashMap<BPlusElementKey, BPlusLeafElement>();
	
	
	private void _test_insert( String str, Integer value) {
		BPlusElementKey key = new BPlusElementKey(str);
		BPlusElementKey key_ = new BPlusElementKey(str);
		map.put(key, new BPlusLeafElement(key,2) );
		Assert.assertEquals( value, map.get(key_).getValue() );
	}
	
	public void test() {
		//ap.put( new BPlusElementKey("prueba"), 2);
		_test_insert( "prueba",2);
	
	}

}
