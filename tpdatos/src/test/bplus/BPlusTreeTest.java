package test.bplus;


import junit.framework.Assert;
import junit.framework.TestCase;

import org.junit.After;
import org.junit.Before;

import documents.keys.DocumentIndexKey;

import bplus.BPlusTreeFacade;
import bplus.exceptions.KeyNotFoundException;

public class BPlusTreeTest extends TestCase {

	@Before
	public void setUp() throws Exception {
	}

	@After
	public void tearDown() throws Exception {
	}

	public void test() throws KeyNotFoundException {
		BPlusTreeFacade tree = new BPlusTreeFacade();
		
		tree.insertElement("bplus", new DocumentIndexKey(2) );
		tree.insertElement("b9999", new DocumentIndexKey(9999) );
		
		Assert.assertEquals( tree.getElement("bplus").getValue(), new Integer(2) );
		
	}
}
