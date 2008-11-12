package test.utils;

import java.util.Iterator;

import junit.framework.Assert;
import junit.framework.TestCase;
import linkedblocks.codification.GammaDistancesBlock;
import exceptions.PersistanceException;

public class GammaDistancesBlockTest extends TestCase {

	public GammaDistancesBlockTest() {
		
	}
	
	public void _benchMarkIteration() throws PersistanceException {
		GammaDistancesBlock block = new GammaDistancesBlock(16384);

		for (int j=0;j<500;j++) {
			block.encodeDistance(j);
		}
	
		Iterator<Integer> it = block.decodeDistances();
		
		
		for (int j=0;j<500;j++){
			if ( it.hasNext() ) {
				Integer value = it.next();
				System.out.println(value);
				Assert.assertEquals(j , value.intValue());
			} else {
				Assert.assertTrue(false);
			}
		}
		
	}
	
	public void testBenchMark() throws PersistanceException {
		for (int i=0;i<10;i++){
			_benchMarkIteration();
		}
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
		_testEncode(distances);

		int[] distances2 = { 1,2 };
		_testEncode(distances2);

		int[] distances31 = { 5 };
		_testEncode(distances31);

		int[] distances3 = { 1,2,3,4,4,4,5 };
		_testEncode(distances3);

		int[] distances4 = { 8,1 };
		_testEncode(distances4);

		int[] distances5 = { 8,2,1,1,41,4,5 };
		_testEncode(distances5);
		
		int[] distances6 = { 9 };
		_testEncode(distances6);
		
		int[] distances7 = { 16 };
		_testEncode(distances7);

		int[] distances8 = { 16000,1,1,1,2 };
		_testEncode(distances8);

		for (int i = 1; i< 100;i++) {
			int[] distance_d = { i, 1 };
			_testEncode(distance_d);
		}*/
/*		
		int[] distances6 = { 7,7,7,7,9000,3,4 };
		_testEncode(distances6);*/

	}
}
