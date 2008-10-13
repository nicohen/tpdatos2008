package test.index;

import junit.framework.TestCase;
import linkedblocks.LinkedBlocksManagerB;
import api.po.persistors.Persistor;
import app.po.persistors.LinkedBlockPersistor;
import exceptions.DataAccessException;

abstract public class TestLinkedBlocksManager<E> extends TestCase {
	
	private LinkedBlocksManagerB<E> linked;
	
	public TestLinkedBlocksManager( Persistor<E> subpersistor, String filename) throws DataAccessException {
		
		
		LinkedBlockPersistor<E> persistor =	new LinkedBlockPersistor<E>(subpersistor);
		linked = new LinkedBlocksManagerB<E>(filename, persistor );
		
	}
	
	protected LinkedBlocksManagerB<E> getObject() {
		return linked;
	}
}
