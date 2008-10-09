package test.files;

import junit.framework.TestCase;
import api.po.files.File;
import app.po.files.BufferedRelativeFile;
import app.po.persistors.BytePersistor;
import app.po.persistors.IntegerPersistor;
import app.po.persistors.StringPersistor;
import exceptions.DataAccessException;
import exceptions.PersistanceException;

public class BufferedRelativeFileTest extends TestCase {
	
	// FIXME: no rethrowear mejor hacer algo con el junit ?
	public void testBufferedRelativeFileBytePersistor() throws DataAccessException, PersistanceException {
		BytePersistor persistor= new BytePersistor();
		File<Byte> file= new BufferedRelativeFile<Byte>("test_buffered_relative_byte.bin",persistor,2);
		try {
			file.add(new Byte((byte)7));
			file.add(new Byte((byte)8));
			file.add(new Byte((byte)9));
			file.add(new Byte((byte)10));
		} catch (PersistanceException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		Byte aux= file.get(0);
		assertEquals(aux, new Byte((byte)7));
		aux= file.get(3);
		assertEquals(aux, new Byte((byte)10));
		aux= file.get(2);
		assertEquals(aux, new Byte((byte)9));
		aux= file.get(1);
		assertEquals(aux, new Byte((byte)8));
		//file.close();
	}
	
	// FIXME: no rethrowear mejor hacer algo con el junit ?
	public void testBufferedRelativeFileIntegerPersistor() throws DataAccessException {
		IntegerPersistor persistor= new IntegerPersistor();
		File<Integer> file= new BufferedRelativeFile<Integer>("test_buffered_relative_integer.bin",persistor,8);
		try {
			file.add(7);
			file.add(8);
			file.add(9);
			file.add(10);
		} catch (PersistanceException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		Integer aux= file.get(0);
		assertEquals(aux,new Integer(7));
		aux= file.get(3);
		assertEquals(aux, new Integer(10));
		aux= file.get(2);
		assertEquals(aux, new Integer(9));
		aux= file.get(1);
		assertEquals(aux, new Integer(8));
		//file.close();

	}
	
	// FIXME: no rethrowear mejor hacer algo con el junit ?
	public void testBufferedRelativeFileStringPersistor() throws DataAccessException {
		StringPersistor persistor= new StringPersistor(20);

		File<String> file= new BufferedRelativeFile<String>("test_buffered_relative_string.bin",persistor,48);
		try {
			file.add("Cuarto");
			file.add("Primero");
			file.add("Tercero");
			file.add("Segundo");
		} catch (PersistanceException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
			
		String aux= file.get(0);
		assertEquals(aux, "Cuarto");
		aux= file.get(3);
		assertEquals(aux, "Segundo");
		aux= file.get(2);
		assertEquals(aux, "Tercero");
		aux= file.get(1);
		assertEquals(aux, "Primero");
		//file.close();
	}
}
