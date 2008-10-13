package test.index;

import java.util.Iterator;

import junit.framework.Assert;
import app.po.persistors.GammaDistancesBlockPersistor;
import exceptions.DataAccessException;
import exceptions.PersistanceException;
import linkedblocks.LinkedBlocksManagerB;
import linkedblocks.codification.GammaDistancesBlock;

public class TestGammaLinkedBlocksManager extends
		TestLinkedBlocksManager<GammaDistancesBlock> {

	
	final static int BLOCK_LENGTH = 512;
	final static int GAMMA_DISTANCES_LENGTH = 508;
	final static int GAMMA_LENGTH = 504;
	
	public TestGammaLinkedBlocksManager() throws DataAccessException {
		super(new GammaDistancesBlockPersistor(GAMMA_DISTANCES_LENGTH), "linkedblock-gamma-test.bin" );
	}

	public void test() throws PersistanceException {
		
		LinkedBlocksManagerB<GammaDistancesBlock> linked = this.getObject();
		
		GammaDistancesBlock gamma1 = new GammaDistancesBlock(GAMMA_LENGTH);
		
		gamma1.encodeDistance(1);
		gamma1.encodeDistance(3);
		gamma1.encodeDistance(4);
		gamma1.encodeDistance(66);

		int firstblock = linked.add(gamma1);

		GammaDistancesBlock gamma2 = new GammaDistancesBlock(GAMMA_LENGTH);
		
		gamma2.encodeDistance(9);
		gamma2.encodeDistance(8);
		gamma2.encodeDistance(7);
		gamma2.encodeDistance(6);

		linked.add(gamma2,firstblock);
		
		Iterator<GammaDistancesBlock> it = linked.get(firstblock);
		
	
		GammaDistancesBlock gamma1_rec = it.next();
		Iterator<Integer> it_gamma1_rec = gamma1_rec.decodeDistances();
		
		Assert.assertEquals( 1, it_gamma1_rec.next().intValue() );
		Assert.assertEquals( 3, it_gamma1_rec.next().intValue() );
		Assert.assertEquals( 4, it_gamma1_rec.next().intValue() );
		Assert.assertEquals( 66, it_gamma1_rec.next().intValue() );
		
		GammaDistancesBlock gamma2_rec = it.next();
		Iterator<Integer> it_gamma2_rec = gamma2_rec.decodeDistances();

		Assert.assertEquals( 9, it_gamma2_rec.next().intValue() );
		Assert.assertEquals( 8, it_gamma2_rec.next().intValue() );
		Assert.assertEquals( 7, it_gamma2_rec.next().intValue() );
		Assert.assertEquals( 6, it_gamma2_rec.next().intValue() );

	}
	
}
