package test.files;
import dto.LinkedBlock;
import junit.framework.TestCase;
import api.po.files.File;
import app.po.files.RelativeFile;
import app.po.persistors.LinkedBlockIntPersistor;
import exceptions.DataAccessException;


public class LinkedBlocksManagerTest extends TestCase {

	// FIXME: no rethrowear mejor hacer algo con el junit ?
	public void testLinkedBlocksPersistor() throws DataAccessException {
		LinkedBlockIntPersistor persistor=new LinkedBlockIntPersistor(24);
		File<LinkedBlock<Integer>> file= new RelativeFile<LinkedBlock<Integer>>("test_relative_block.bin",persistor);
		LinkedBlock<Integer> reg=new LinkedBlock<Integer>();
		reg.setDoc(1);
		reg.setDoc(2);
		reg.setDoc(3);
		reg.setDoc(4);
		reg.setDoc(5);
		file.add(reg);
		
		
		LinkedBlock<Integer> aux= file.get(0);
		assertEquals(aux, reg);
		
	}
	
	
}