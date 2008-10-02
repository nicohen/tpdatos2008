package test.index;

import java.util.Iterator;
import java.util.List;

import dto.DocumentDto;

import junit.framework.TestCase;
import api.QueryEngine;
import exceptions.BusinessException;
import exceptions.DataAccessException;

public abstract class TestQueryEngine extends TestCase {
	
	private QueryEngine engine;
	
	protected TestQueryEngine ( QueryEngine object ) {
		this.engine = object;
	}
	
	protected void setTestObject( QueryEngine object ) {
		this.engine = object;
	}
	

	public void testInsertRetrieve() throws BusinessException, DataAccessException{
		
		// FIXME: encontrar una manera de insertar en el index de QueryEngine
		
		engine.prepareDocumentInsert("documento1").insertWord("gato");
		engine.prepareDocumentInsert("documento2").insertWord("gato");
		engine.prepareDocumentInsert("documento3").insertWord("gato");
		engine.prepareDocumentInsert("documento4").insertWord("gato");
		engine.prepareDocumentInsert("documento5").insertWord("gato");
		engine.prepareDocumentInsert("documento1").insertWord("perro");
		engine.prepareDocumentInsert("documento2").insertWord("perro");
		engine.prepareDocumentInsert("documento3").insertWord("perro");
		engine.prepareDocumentInsert("documento4").insertWord("perro");
		engine.prepareDocumentInsert("documento5").insertWord("perro");
		
		List<DocumentDto> list;

		list=engine.executeQuery("gato");
		
		// FIXME: utilizar los asserts correspondientes
		
		for(DocumentDto doc : list ){
			System.out.println(doc);
		}
		
	}

	
	
}
