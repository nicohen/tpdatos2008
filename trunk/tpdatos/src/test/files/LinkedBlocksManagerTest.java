package test.files;
import java.util.ArrayList;

import junit.framework.TestCase;
import api.LinkedBlocksManager;
import app.po.persistors.LinkedBlockIntPersistor;
import exceptions.DataAccessException;


public class LinkedBlocksManagerTest extends TestCase {

	// FIXME: no rethrowear mejor hacer algo con el junit ?
	public void testLinkedBlocksManager() throws DataAccessException {
		LinkedBlockIntPersistor persistor=new LinkedBlockIntPersistor(24);
		LinkedBlocksManager<Integer> manager=new LinkedBlocksManager<Integer>("test_relative_block.bin",5 , persistor);
		manager.add(1, 0);
		manager.add(2, 0);
		manager.add(3, 0);
		manager.add(4, 0);
		manager.add(5, 0);
		manager.add(6, 0);
		manager.add(7, 0);
		manager.add(8, 0);
		manager.add(9, 0);
		manager.add(17, 5);
		manager.add(18, 5);
		manager.add(19, 5);
		manager.add(20, 5);
		manager.add(21, 5);
		manager.add(22, 5);
		manager.add(23, 5);
		manager.add(10, 0);
		manager.add(11, 0);
		manager.add(12, 0);
		manager.add(13, 0);
		manager.add(14, 0);
		manager.add(15, 0);
		manager.add(16, 0);
		aux=manager.get(0);
		//deberia ser: 1-2-3-4-5-6-7-8-9-10-11-12-13-14-15-16
		aux=manager.get(5);
		//deberia ser: 17-18-19-20-21-22-23
		//assertEquals(aux, a);
		
	}
	
}