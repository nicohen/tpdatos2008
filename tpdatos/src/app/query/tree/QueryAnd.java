package app.query.tree;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;

import api.query.tree.Query;

public class QueryAnd extends CompositeQuery {

	@Override
	String operatorName() {
		return "and";
	}

	public Iterator<Integer> iterator() {

		// generar un hashset de cada iterator, excepto para el primero
		
		List<Query> querys = this.getQuerys();
		
		if (querys.size() == 0) return new ArrayList().iterator();
		if (querys.size() == 1) return querys.get(0).iterator();
		
		List<HashSet<Integer> > hashsets = 
			new ArrayList<HashSet<Integer> >();
		
		boolean esprimera = true;
		Iterator<Integer> it_primera = null;
		
		for (Query q : querys) {
			if (esprimera) {
				it_primera = q.iterator();
				esprimera = false;
			} else {
				HashSet<Integer> new_hashset = new HashSet<Integer>();
				
				Iterator<Integer> it = q.iterator();
				while (it.hasNext() ) {
					new_hashset.add(it.next() );
				}
				
				hashsets.add(new_hashset);
			}
		}
		
		List<Integer> lista = new ArrayList<Integer> ();
		
		while (it_primera.hasNext() ) {
			boolean todos = true;
			
			Integer id = it_primera.next();
			
			for ( HashSet<Integer> hashset : hashsets) {
				if (! hashset.contains(id )) {
					todos = false;
					break;
				}
			}
			

			if (todos) {
				lista.add(id);
			}
			
		}
		
		return lista.iterator();
	}


}
