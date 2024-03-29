package test.index;

import junit.framework.Assert;
import junit.framework.TestCase;
import api.dao.documents.DocumentsDictionary;
import dto.DocumentDto;
import exceptions.BusinessException;

abstract public class TestDocumentsDictionary extends TestCase {
	
	private DocumentsDictionary dict ;
	
	protected TestDocumentsDictionary( DocumentsDictionary dict ) {
			this.dict = dict;
		
	}
	
	
	public void _test_insert( String documentname ) throws BusinessException {
		DocumentDto docdto = new DocumentDto( documentname );
		
		Integer id = dict.insertDocument(docdto);
		
		DocumentDto docrecuperado;
		
		docrecuperado = dict.getDocument(id);
		
		Assert.assertEquals( docrecuperado.getFileName(), docdto.getFileName() );
		
	}
	
	public void test() throws BusinessException {
		_test_insert("weeqw");
		_test_insert("twwtwetwewte");
		_test_insert("document");
		_test_insert("document");
	}
}
