package test.index;

import java.util.Iterator;

import org.junit.Assert;

import linkedblocks.LinkedBlocksManagerB;
import api.po.persistors.Persistor;
import app.po.persistors.IntegerPersistor;
import exceptions.DataAccessException;
import exceptions.PersistanceException;

public class TestIntegerLinkedBlocksManager extends
		TestLinkedBlocksManager<Integer> {

	public TestIntegerLinkedBlocksManager() throws DataAccessException {
		super(new IntegerPersistor() );
	}
	
	
	public void test() throws PersistanceException {
		LinkedBlocksManagerB<Integer> linked = this.getObject();

		
		linked.add(0);
		linked.add(1);
		linked.add(2);
		int ultimobloque = linked.add(3);
		linked.add(9,ultimobloque);
		linked.add(22,ultimobloque);
		
		Iterator<Integer> it = linked.get(ultimobloque);
		
		Assert.assertEquals ( 3, it.next().intValue() );
		Assert.assertEquals ( 9, it.next().intValue() );
		Assert.assertEquals ( 22, it.next().intValue() );
	}

}
