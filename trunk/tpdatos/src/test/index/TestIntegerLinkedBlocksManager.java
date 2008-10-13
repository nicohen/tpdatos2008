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
		super(new IntegerPersistor(), "linkedblock-integer-test.bin" );
	}
	
	
	public void test() throws PersistanceException {
		LinkedBlocksManagerB<Integer> linked = this.getObject();

		
		linked.add(0);
		linked.add(0x11);
		linked.add(0x22);
		int ultimobloque = linked.add(0x33);
		linked.add(0x19,ultimobloque);
		linked.add(0x22,ultimobloque);
		
		Iterator<Integer> it = linked.get(ultimobloque);
		
		Assert.assertEquals ( 0x33, it.next().intValue() );
		Assert.assertEquals ( 0x19, it.next().intValue() );
		Assert.assertEquals ( 0x22, it.next().intValue() );
	}

}
