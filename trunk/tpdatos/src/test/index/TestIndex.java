package test.index;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

import junit.framework.Assert;
import junit.framework.TestCase;
import api.Index;
import exceptions.BusinessException;

abstract public class TestIndex extends TestCase {
	private Index testObject;
	
	abstract protected Index createTestObject() throws BusinessException;
	
	public TestIndex( ) throws BusinessException {
		testObject = createTestObject();
	}
	
	private void test_entry( String word, List<Integer> lista) throws BusinessException {

		Iterator<Integer> original = lista.iterator();
		
		int j=0;
		for ( Integer id : lista ) {
			j++;
			testObject.insertWord(word, id);
		}
		
		Iterator<Integer> recuperado = testObject.getDocuments(word).iterator();
		Iterator<Integer> it=recuperado;
		// comparar el original con el recuperado
		
		
		while ( original.hasNext() ) {
			if (! it.hasNext() ) {
				Assert.assertTrue(false);
			}
			
			Assert.assertEquals( original.next(), recuperado.next() );
		}
		
		
	}
	
	private void test_entry ( String word, int[] ids ) throws BusinessException {
		List<Integer> lista = new LinkedList<Integer>();
		
		for (int id : ids ) {
			lista.add(new Integer(id));
		}
		
		test_entry(word,lista);
		
	}
	
	public void test() throws BusinessException {
		int[] ids = {1,4,5,76,566};
		test_entry("prueba", ids );

		int[] ids2 = {1,44,45,576,11566};
		test_entry("prueba2", ids2 );

		int[] ids3 = {1,9,9,9,9,9};
		test_entry("prueba3", ids3 );
		
		List<Integer> lista = new ArrayList<Integer>() ;
		
		for (int i=0; i<500; i++) {
			lista.add(i);
		}
		
		test_entry("prueba4", lista);

		lista.clear();
		for (int i=0; i<400; i++) {
			lista.add(i/6);
		}

		test_entry("prueba5", lista);
		
	}
	
}
