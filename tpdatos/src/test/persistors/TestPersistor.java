package test.persistors;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;

import junit.framework.Assert;
import junit.framework.TestCase;
import api.po.persistors.Persistor;
import exceptions.PersistanceException;


abstract public class TestPersistor<E> extends TestCase {
	private Persistor<E> persistor;
	
	abstract protected Persistor<E> createTestObject() ;
	
	protected void _test_object ( E elementoInsertado ) throws PersistanceException {
		
		ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
		DataOutputStream outputStream = new DataOutputStream( byteArrayOutputStream );
		
		persistor.write(elementoInsertado, outputStream);
		
		ByteArrayInputStream inputStream = 
			new ByteArrayInputStream( byteArrayOutputStream.toByteArray() );
		
		E elementoRecuperado = persistor.read(new DataInputStream(inputStream));
		
		
		Assert.assertEquals( elementoInsertado, elementoRecuperado );
	}
	
	public TestPersistor() {
		persistor = createTestObject();
	}
	
}
