package test.query;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import app.query.tree.AbstractQuery;

public class MockQuery extends AbstractQuery {

	private List<Integer> lista;
	
	public MockQuery() {
		lista = new ArrayList<Integer>();
	}
	
	
	public void add ( Integer id ) {
		lista.add(id);
	}
	

	public void dump(int ntabs) {
	}


	public List<Integer> execute() {
		return lista;
	}

}
