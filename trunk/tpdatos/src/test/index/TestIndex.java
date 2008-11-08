package test.index;

import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;
import java.util.Set;

import junit.framework.Assert;
import junit.framework.TestCase;
import api.Index;
import app.bo.MockIndex;
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
	
	static String[] words = { "static", "String", "words", "random" ,"java", "util" }; 
	
	private String randomWord(Random random) {
		return words[random.nextInt(6)];
	}
	
	public void test_completo() throws BusinessException {
		
		
		Set<String> word_set = new HashSet<String>();
		
		Index ideal_index = new MockIndex();
		
		// se le especifica la semilla para poder debuggear situaciones iguales
		// de maneras repetidas
		
		Random random = new Random(0);
		
		for (int documentid=1;documentid<2000;documentid++) {
			// agregar entradas
			
			int numwords = random.nextInt(100)+59;
			
			for (int j=0; j<numwords; j++) {
			
				String word = randomWord(random) + String.valueOf( random.nextInt(100) );
				//String word=wordAux.substring(0, 3);
				word_set.add(word);
			
				// realizar el mismo insert en ambos indices
				testObject.insertWord(word, documentid);
				ideal_index.insertWord(word, documentid);
				
				// registrar el word en el set
				word_set.add(word);
			
			}
		}
		
		
		// para cada palabra en el set
		
		for (String word : word_set ) {
			// verificar si ambos indices mantienen los mismos
			// documentos, y en el mismo orden
			List<Integer> docs = testObject.getDocuments(word);
			List<Integer> docs_ideal = ideal_index.getDocuments(word);
			
			Assert.assertEquals(docs_ideal.size(), docs.size() );
			
			for (int i=0; i<docs.size(); i++) {
				Assert.assertEquals( docs_ideal.get(i), docs.get(i) );
			}
			
		}
	}
	
	public void test() throws BusinessException {
	/*	int[] ids = {1,4,5,76,566};
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
*/		
	}
	
}
