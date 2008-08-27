import java.io.FileNotFoundException;
import java.io.IOException;

import junit.framework.TestCase;
import persistors.BytePersistor;
import exceptions.DataAccessException;
import files.File;
import files.SecuencialFile;


public class SecuentialFileTest extends TestCase {
	public SecuentialFileTest() {
		
	}

	public void testMe() throws DataAccessException {
		BytePersistor persistor= new BytePersistor();
		try {
			File<Byte> file= new SecuencialFile<Byte>("c:/datos.bin",persistor);
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

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}
}
