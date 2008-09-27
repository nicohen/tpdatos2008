package test.files;
import java.util.ArrayList;

import junit.framework.TestCase;
import utils.KeyCodificationUtils;
import api.LinkedBlocksManager;
import app.po.persistors.LinkedBlockByteArrayPersistor;
import app.po.persistors.LinkedBlockIntPersistor;
import exceptions.DataAccessException;

public class LinkedBlocksManagerTest extends TestCase {

	// FIXME: no rethrowear mejor hacer algo con el junit ?
	public void testLinkedBlocksManager() throws DataAccessException {
		LinkedBlockIntPersistor persistor=new LinkedBlockIntPersistor(24);
		LinkedBlocksManager<Integer> manager=new LinkedBlocksManager<Integer>("test_relative_block_int.bin",5 , persistor);
		ArrayList<Integer> aux;
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
	public void testLinkedBlocksBytePersistor() throws DataAccessException {
		LinkedBlockByteArrayPersistor persistor=new LinkedBlockByteArrayPersistor(24);
		LinkedBlocksManager<byte[]> manager=new LinkedBlocksManager<byte[]>("test_relative_block.bin",5 , persistor);
		ArrayList<byte[]> aux;
		Integer i;
		manager.add(KeyCodificationUtils.gammaEncode(10), 0);
		//manager.add(KeyCodificationUtils.gammaEncode(11), 0);
		//manager.add(KeyCodificationUtils.gammaEncode(12), 0);
		//manager.add(KeyCodificationUtils.gammaEncode(13), 0);
		aux=manager.get(0);
		i=KeyCodificationUtils.gammaDecode(aux.get(0));
		
		
		
	}
	
}