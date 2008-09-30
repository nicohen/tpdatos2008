package test;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import junit.framework.Assert;
import junit.framework.TestCase;

public class TestIterator extends TestCase {
	public void test() {
		List<Integer> lista = new ArrayList<Integer>();
		
		lista.add(1);
		lista.add(2);
		lista.add(5);
		
		Iterator<Integer> it = lista.iterator();
		
		Assert.assertTrue( it.next() == 1);
		Assert.assertTrue( it.next() == 2);
		Assert.assertTrue( it.next() == 5);
		
	}
}
