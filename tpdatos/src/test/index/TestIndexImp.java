package test.index;

import java.util.ArrayList;
import java.util.Iterator;

import junit.framework.Assert;

import api.QueryEngine;
import api.bo.Index;
import app.bo.IndexImp;
import exceptions.BusinessException;

public class TestIndexImp extends TestIndex {

	public TestIndexImp() throws BusinessException {
		//super();
		testInsertRetrieve();
	}

	@Override
	protected IndexImp createTestObject() throws BusinessException {
		return new IndexImp("index.bin", 4096) ;
	}
	
	protected void testInsertRetrieve() throws BusinessException{
		IndexImp index = this.createTestObject();
		QueryEngine engine=new QueryEngine(index);
		ArrayList<Integer> list;
		Iterator<Integer> it;
		index.insertWord("perro", 1);
		index.insertWord("perro", 2);
		index.insertWord("perro", 3);
		index.insertWord("perro", 4);
		index.insertWord("perro", 5);
		index.insertWord("gato", 6);
		index.insertWord("gato", 7);
		index.insertWord("gato", 8);
		index.insertWord("gato", 9);
		index.insertWord("gato", 10);
		
		it=engine.ExecuteQuery("gato");
		int i=6;
		
		while(it.hasNext()){
			it.next();
			//Assert.assertTrue(it.next()==i);
			if (i==10)
			i=6;
			else
			i++;
		}
		
	}

}
