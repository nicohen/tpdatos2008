package test.index;

import exceptions.DataAccessException;
import api.po.persistors.Persistor;
import app.po.persistors.GammaDistancesBlockPersistor;
import app.po.persistors.IntegerPersistor;
import app.po.persistors.LinkedBlockPersistor;
import junit.framework.TestCase;
import linkedblocks.LinkedBlocksManagerB;
import linkedblocks.codification.GammaDistancesBlock;

abstract public class TestLinkedBlocksManager<E> extends TestCase {
	
	private LinkedBlocksManagerB<E> linked;
	
	public TestLinkedBlocksManager( Persistor<E> subpersistor) throws DataAccessException {
		
		
		LinkedBlockPersistor<E> persistor =	new LinkedBlockPersistor<E>(subpersistor);
		linked = new LinkedBlocksManagerB<E>("linkedblock-test.bin", persistor );
		
	}
	
	protected LinkedBlocksManagerB<E> getObject() {
		return linked;
	}
}
