package test.bplus;

import api.bo.BPlusTree.BPlusTreeBo;
import app.bo.bplus.BPlusTreeBoTest;

public class TestBPlusTreeBoTest extends TestBPlusTreeBo {

	@Override
	protected BPlusTreeBo createTestObject() {
		// TODO Auto-generated method stub
		return new BPlusTreeBoTest();
	}

}
