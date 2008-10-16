package test.bplus;

import java.util.LinkedList;
import java.util.List;

import junit.framework.Assert;
import junit.framework.TestCase;
import api.bo.BPlusTree.BPlusTreeBo;
import app.bo.bplus.BPlusTreeBoTest;
import bplus.elements.BPlusLeafElement;
import bplus.exceptions.KeyNotFoundException;
import bplus.keys.BPlusElementKey;
import exceptions.DataAccessException;


abstract public class TestBPlusTreeBo extends TestCase {

	protected BPlusTreeBo bo ;

	abstract protected BPlusTreeBo createTestObject() throws DataAccessException ;
	
	public TestBPlusTreeBo() throws DataAccessException {
		bo = createTestObject();
	}
	
	public void _test_insert( String word, Integer value) throws KeyNotFoundException, DataAccessException {
		
		BPlusElementKey key = new BPlusElementKey(word);
		bo.insertElement( new BPlusLeafElement( key , value) );

		BPlusElementKey key_ = new BPlusElementKey(word);
		Assert.assertEquals(value , bo.getElement( key_ ).getValue() );
	}
	
	public void _assert_key_value( String word, Integer value ) throws KeyNotFoundException, DataAccessException {
		BPlusElementKey key = new BPlusElementKey(word);
		 Assert.assertEquals(value, bo.getElement( key ).getValue() );
	}

/*	public void _test_update( String word, Integer value) throws KeyNotFoundException {
		
		BPlusElementKey key = new BPlusElementKey(word);
		bo.updateElement( new BPlusLeafElement( key , value) );

		BPlusElementKey key_ = new BPlusElementKey(word);
		Assert.assertEquals(value , bo.getElement( key_ ).getValue() );
	}*/
	
	
	public void test() throws KeyNotFoundException, DataAccessException {
		
		// arbol b+ que funciona seguro
		BPlusTreeBoTest bplustest = new BPlusTreeBoTest();
		
		// lista de claves que fueron insertadas en ambos b+
		List<String> lista_claves = new LinkedList<String>();
		
		for (int i=0; i<10; i++) {
			String clave = String.valueOf(i);
			
			BPlusLeafElement element = new BPlusLeafElement(new BPlusElementKey(clave),i);
			BPlusLeafElement element_test = new BPlusLeafElement(new BPlusElementKey(clave),i);
			
			// inserto el elemento en ambos bplus
			bo.insertElement(element);
			bplustest.insertElement(element_test);
			
			// y en la lista, la calve
			lista_claves.add(clave);
		}
		
		
		for (String clave : lista_claves ) {
			
			BPlusElementKey elementKey = new BPlusElementKey(clave);
			BPlusLeafElement element = bo.getElement(elementKey);
			BPlusLeafElement element_test = bplustest.getElement(elementKey);

			Assert.assertEquals(element_test.getValue(), element.getValue() );
			
		}
		
		
		
		
		//bo.insertElement( new BPlusLeafElement( new BPlusElement) );
/*		_test_insert( "bplus", 2);
		this.bo.dump();
		System.out.println("--------------------------------------------------------");
		_test_insert( "b9999", 9999);
		this.bo.dump();
		System.out.println("--------------------------------------------------------");
		_test_insert( "parseaste", 34);
		this.bo.dump();
		System.out.println("--------------------------------------------------------");
		_test_insert( "documentos", 254);
		this.bo.dump();
		System.out.println("--------------------------------------------------------");
		_test_insert( "laruta", 1000);
		this.bo.dump();
		System.out.println("--------------------------------------------------------");
		_test_insert( "perro", 1000);
		this.bo.dump();
		System.out.println("--------------------------------------------------------");
		_test_insert( "gato", 1200);
		this.bo.dump();
		System.out.println("--------------------------------------------------------");
		_test_insert( "gatiperro", 3);
		this.bo.dump();
		
		for (int i=0; i < 1200;i++){
			BPlusElementKey key;
			
			key = new BPlusElementKey( String.valueOf(i) );
			bo.insertElement(new BPlusLeafElement( key, i));
			
			key = new BPlusElementKey( "z" + String.valueOf(i) );
			bo.insertElement(new BPlusLeafElement( key, i));

			key = new BPlusElementKey( "_" + String.valueOf(i) );
			bo.insertElement(new BPlusLeafElement( key, i));

			key = new BPlusElementKey( "p" + String.valueOf(i) );
			bo.insertElement(new BPlusLeafElement( key, i));
			
		}
		
		_assert_key_value("gato", 1200);
		_assert_key_value("gatiperro", 3);		
		_assert_key_value("perro", 1000);*/		
	}

}
