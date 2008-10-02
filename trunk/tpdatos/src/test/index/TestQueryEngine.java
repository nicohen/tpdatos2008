package test.index;

import junit.framework.TestCase;
import api.QueryEngine;
import exceptions.BusinessException;
import exceptions.DataAccessException;

public abstract class TestQueryEngine extends TestCase {
	
	private QueryEngine testObject;
	
	protected TestQueryEngine ( QueryEngine object ) {
		this.testObject = object;
	}
	
	protected void setTestObject( QueryEngine object ) {
		this.testObject = object;
	}
	

	public void testInsertRetrieve() throws BusinessException, DataAccessException{
		
		// FIXME: encontrar una manera de insertar en el index de QueryEngine
		
/*		DocumentsDictionary dicc=new DocumentsDictionaryImp();
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
*/		
	}

	
	
}
