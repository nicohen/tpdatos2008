package test.index;

import java.util.Iterator;

import junit.framework.TestCase;
import linkedblocks.LinkedBlocksManager;
import linkedblocks.codification.GammaDistancesBlock;

import org.junit.Assert;

import app.po.persistors.GammaDistancesBlockPersistor;
import app.po.persistors.LinkedBlockPersistor;
import exceptions.DataAccessException;
import exceptions.PersistanceException;

public class TestLinkedBlocksManager extends TestCase {
	public void test() throws DataAccessException, PersistanceException {

		int blockSize = 4096;
		LinkedBlocksManager<GammaDistancesBlock> manager;
		
		GammaDistancesBlockPersistor subpersistor = new GammaDistancesBlockPersistor(blockSize-4);
		LinkedBlockPersistor<GammaDistancesBlock> persistor=new LinkedBlockPersistor<GammaDistancesBlock>(subpersistor);
		manager=new LinkedBlocksManager<GammaDistancesBlock>("index2.bin", persistor);
		
		GammaDistancesBlock gamma1 = new GammaDistancesBlock(blockSize-8);
		
		int initBlock = manager.add(gamma1);
		
		for(int i=1;i<40000;i++) {
			//manager.add(KeyCodificationUtils.gammaEncode(i), 0);
			try {
				gamma1.encodeDistance(i);
				manager.updateLast(gamma1, initBlock);
			} catch (PersistanceException e ) {
				GammaDistancesBlock newGamma = 
					new GammaDistancesBlock(blockSize-8);
				
				newGamma.encodeDistance(i);
				manager.add(newGamma,initBlock);
				gamma1 = newGamma;
			}
		}
		
		Iterator<GammaDistancesBlock> it = manager.get(initBlock);
		
		int j=1;
		while (it.hasNext() ){
			GammaDistancesBlock gammaBlock = it.next();
			Iterator<Integer> distancesIt = gammaBlock.decodeDistances();
			
			while (distancesIt.hasNext() ) {
				Assert.assertEquals(distancesIt.next().intValue(), j);
				j++;
			}
		}
		
	}
}
