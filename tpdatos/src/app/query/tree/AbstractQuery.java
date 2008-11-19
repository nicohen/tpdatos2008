package app.query.tree;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import api.query.tree.Query;

abstract public class AbstractQuery implements Query {

	public List<Integer> executeGetList() {
		Iterator<Integer> it = this.execute();
		
		List<Integer> aux = new ArrayList<Integer>();
		while (it.hasNext() ) {
			aux.add(it.next() );
		}
		
		return aux;
	}

}
