package test.files;
import junit.framework.TestCase;
import api.po.files.File;
import app.po.files.RelativeFile;
import app.po.persistors.BytePersistor;
import app.po.persistors.IntegerPersistor;
import app.po.persistors.StringPersistor;
import exceptions.DataAccessException;


public class RelativelFileTest extends TestCase {

	// FIXME: no rethrowear mejor hacer algo con el junit ?
	public void testSecuentialFileBytePersistor() throws DataAccessException {
		BytePersistor persistor= new BytePersistor();
		File<Byte> file= new RelativeFile<Byte>("test_relative_byte.bin",persistor);
		file.add(new Byte((byte)7));
		file.add(new Byte((byte)8));
		file.add(new Byte((byte)9));
		file.add(new Byte((byte)10));
		
		Byte aux= file.get(0);
		assertEquals(aux, new Byte((byte)7));
		aux= file.get(3);
		assertEquals(aux, new Byte((byte)10));
		aux= file.get(2);
		assertEquals(aux, new Byte((byte)9));
		aux= file.get(1);
		assertEquals(aux, new Byte((byte)8));

	}
	
	// FIXME: no rethrowear mejor hacer algo con el junit ?
	public void testSecuentialFileIntegerPersistor() throws DataAccessException {
		IntegerPersistor persistor= new IntegerPersistor();
		File<Integer> file= new RelativeFile<Integer>("test_relative_integer.bin",persistor);
		file.add(7);
		file.add(8);
		file.add(9);
		file.add(10);
		
		Integer aux= file.get(0);
		assertEquals(aux,new Integer(7));
		aux= file.get(3);
		assertEquals(aux, new Integer(10));
		aux= file.get(2);
		assertEquals(aux, new Integer(9));
		aux= file.get(1);
		assertEquals(aux, new Integer(8));

	}
	
	// FIXME: no rethrowear mejor hacer algo con el junit ?
	public void testSecuentialFileStringPersistor() throws DataAccessException {
		StringPersistor persistor= new StringPersistor(20);

		File<String> file= new RelativeFile<String>("test_relative_string.bin",persistor);
		file.add("Cuarto");
		file.add("Primero");
		file.add("Tercero");
		file.add("Segundo");
			
		String aux= file.get(0);
		assertEquals(aux, "Cuarto");
		aux= file.get(3);
		assertEquals(aux, "Segundo");
		aux= file.get(2);
		assertEquals(aux, "Tercero");
		aux= file.get(1);
		assertEquals(aux, "Primero");
	}
}