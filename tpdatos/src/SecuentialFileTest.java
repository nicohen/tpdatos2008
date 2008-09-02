import java.io.FileNotFoundException;
import java.io.IOException;

import junit.framework.TestCase;

//import junit.framework.TestCase;
import persistors.BytePersistor;
import persistors.StringPersistor;
import exceptions.DataAccessException;
import files.File;
import files.IFile;
import files.SecuencialFile;


public class SecuentialFileTest extends TestCase {
	public SecuentialFileTest() {
		
	}

	// FIXME: no rethrowear mejor hacer algo con el junit ?
	public void testSecuentialFileBytePersistor() throws DataAccessException {
		BytePersistor persistor= new BytePersistor();
		File<Byte> file= new SecuencialFile<Byte>("test_secuencial_byte.bin",4,persistor);
		file.add(new Byte((byte)7));
		file.add(new Byte((byte)8));
		file.add(new Byte((byte)9));
		file.add(new Byte((byte)10));
		
		Byte aux= file.get(0);
		System.out.println(aux);
		assertEquals(aux, new Byte((byte)7));
		aux= file.get(3);
		System.out.println(aux);
		assertEquals(aux, new Byte((byte)10));
		aux= file.get(2);
		System.out.println(aux);
		assertEquals(aux, new Byte((byte)9));
		aux= file.get(1);
		System.out.println(aux);
		assertEquals(aux, new Byte((byte)8));

	}
	// FIXME: no rethrowear mejor hacer algo con el junit ?
	public void testSecuentialFileStringPersistor() throws DataAccessException {
		StringPersistor persistor= new StringPersistor(10);

		File<String> file= new SecuencialFile<String>("test_secuencial_string.bin",256,persistor);
		file.add("Cuarto");
		file.add("Primero");
		file.add("Tercero");
		file.add("Segundo");
			
		String aux= file.get(0);
		System.out.println("["+aux+"]");
		assertEquals(aux, "Cuarto");
		aux= file.get(3);
		System.out.println(aux);
		assertEquals(aux, "Segundo");
		aux= file.get(2);
		System.out.println(aux);
		assertEquals(aux, "Tercero");
		aux= file.get(1);
		System.out.println(aux);
		assertEquals(aux, "Primero");

	//		file.delete();

	}
}
