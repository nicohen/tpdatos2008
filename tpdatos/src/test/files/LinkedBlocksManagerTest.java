package test.files;
import java.util.ArrayList;

import dto.LinkedBlock;
import junit.framework.TestCase;
import api.LinkedBlocksManager;
import api.po.files.File;
import app.po.files.RelativeFile;
import app.po.persistors.LinkedBlockIntPersistor;
import exceptions.DataAccessException;


public class LinkedBlocksManagerTest extends TestCase {

	// FIXME: no rethrowear mejor hacer algo con el junit ?
/*	public void testLinkedBlocksPersistor() throws DataAccessException {
		LinkedBlockIntPersistor persistor=new LinkedBlockIntPersistor(24);
		File<LinkedBlock<Integer>> file= new RelativeFile<LinkedBlock<Integer>>("test_relative_block.bin",persistor);
		LinkedBlock<Integer> reg=new LinkedBlock<Integer>();
		reg.setDoc(1);
		reg.setDoc(2);
		reg.setDoc(3);
		reg.setDoc(4);
		reg.setDoc(5);
		file.add(reg);
		LinkedBlock<Integer> reg2=new LinkedBlock<Integer>();
		reg2.setDoc(6);
		reg2.setDoc(7);
		reg2.setDoc(8);
		reg2.setDoc(9);
		reg2.setDoc(10);
		file.add(reg2);
		LinkedBlock<Integer> reg3=new LinkedBlock<Integer>();
		reg.setDoc(11);
		reg.setDoc(12);
		reg.setDoc(13);
		reg.setDoc(14);
		reg.setDoc(15);
		file.add(reg3);
		LinkedBlock<Integer> reg4=new LinkedBlock<Integer>();
		reg2.setDoc(16);
		reg2.setDoc(17);
		reg2.setDoc(18);
		reg2.setDoc(19);
		reg2.setDoc(20);
		file.add(reg4);
		
		LinkedBlock<Integer> aux= file.get(0);
		LinkedBlock<Integer> aux2= file.get(1);
		LinkedBlock<Integer> aux3= file.get(2);
		LinkedBlock<Integer> aux4= file.get(3);
		//assertEquals(aux, reg);
		
	}*/
	public void testLinkedBlocksManager() throws DataAccessException {
		LinkedBlockIntPersistor persistor=new LinkedBlockIntPersistor(24);
		LinkedBlocksManager<Integer> manager=new LinkedBlocksManager<Integer>("test_relative_block.bin",5 , persistor);
		ArrayList<Integer> aux;
		manager.add(1, 0);
		manager.add(2, 0);
		manager.add(3, 0);
		manager.add(4, 0);
		manager.add(5, 0);
		manager.add(6, 0);
		manager.add(7, 0);
		manager.add(8, 0);
		aux=manager.get(0);
		
		//assertEquals(aux, reg);
		
	}
	
}