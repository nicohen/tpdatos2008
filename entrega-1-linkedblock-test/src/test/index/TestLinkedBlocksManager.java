package test.index;

import java.util.Iterator;

import exceptions.DataAccessException;
import junit.framework.Assert;
import junit.framework.TestCase;
import linkedblocks.utils.KeyCodificationUtils;

public class TestLinkedBlocksManager extends TestCase {
	public void test() throws DataAccessException {
/*		LinkedBlockByteArrayPersistor persistor=new LinkedBlockByteArrayPersistor(4096);
		Iterator<byte[]> it;
		int j=0;
		VariableLinkedBlocksManager manager=new VariableLinkedBlocksManager("index1.bin", persistor);
		for(int i=0;i<40000;i++)
		manager.add(KeyCodificationUtils.gammaEncode(i), 0);
		//for(int i=0;i<400;i++)
		it=manager.get(0);
		while (it.hasNext()){
			
			Assert.assertTrue(KeyCodificationUtils.gammaDecode(it.next())==j);
			j++;	
		}
*/		
	}
}