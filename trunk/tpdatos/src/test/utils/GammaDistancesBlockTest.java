package test.utils;

import java.util.Iterator;

import exceptions.PersistanceException;
import junit.framework.Assert;
import junit.framework.TestCase;
import linkedblocks.codification.GammaDistancesBlock;

public class GammaDistancesBlockTest extends TestCase {

	public GammaDistancesBlockTest() {
		
	}
	
	public void _testEncode( int[] distances ) throws PersistanceException {
		GammaDistancesBlock block = new GammaDistancesBlock(16384);

		for ( int dist : distances ) {
			block.encodeDistance(dist);
		}
		Iterator<Integer> it = block.decodeDistances();
		
		
		for ( int dist : distances ) {
			if ( it.hasNext() ) {
				Integer value = it.next();
				System.out.println(value);
				Assert.assertEquals(dist , value.intValue());
			} else {
				Assert.assertTrue(false);
			}
		}
		
	}
	
	public void test() throws PersistanceException {
		/*int[] distances = { 1,1,1,1 };
		_testEncode(distances);*/

		int[] distances2 = { 1,2 };
		_testEncode(distances2);
/*
		int[] distances3 = { 1,2,3,4,4,4,5 };
		_testEncode(distances3);

		int[] distances4 = { 9,2,1,1,41,4,5 };
		_testEncode(distances4);
		
		int[] distances5 = { 7,7,7,7,9000,3,4 };
		_testEncode(distances5);*/

	}
}
