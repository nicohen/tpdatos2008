package test.index;

import java.util.ArrayList;
import java.util.Iterator;

import dto.DocumentDto;

import junit.framework.Assert;
import api.QueryEngine;
import api.dao.documents.DocumentsDictionary;
import app.bo.IndexImp;
import app.dao.documents.DocumentsDictionaryImp;
import exceptions.BusinessException;
import exceptions.DataAccessException;

public class TestIndexImp extends TestIndex {

	public TestIndexImp() throws BusinessException {
		//super();
	}

	@Override
	protected IndexImp createTestObject() throws BusinessException {
		return new IndexImp("index.bin", 4096) ;
	}
	
	public void testInsertRetrieve() throws BusinessException, DataAccessException{
		IndexImp index = this.createTestObject();
		DocumentsDictionary dicc=new DocumentsDictionaryImp();
		QueryEngine engine=new QueryEngine(index,dicc);
		ArrayList<Integer> list;
		Iterator<DocumentDto> it;
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
			//Assert.assertTrue(it.next()==i);
			if (i==10)
			i=6;
			else
			i++;
		}
		
	}

}
