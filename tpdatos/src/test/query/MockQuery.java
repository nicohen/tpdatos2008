package test.query;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import api.query.tree.Query;

public class MockQuery implements Query {

	private List<Integer> lista;
	
	public MockQuery() {
		lista = new ArrayList<Integer>();
	}
	
	
	public void add ( Integer id ) {
		lista.add(id);
	}
	

	public void dump(int ntabs) {
	}


	public Iterator<Integer> iterator() {
		return lista.iterator();
	}

}
