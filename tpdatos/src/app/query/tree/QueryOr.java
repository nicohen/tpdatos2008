package app.query.tree;

import java.util.HashSet;
import java.util.Iterator;

import api.query.tree.Query;

public class QueryOr extends CompositeQuery {

	@Override
	String operatorName() {
		return "or";
	}

	public Iterator<Integer> iterator() {
		
		// recorrer todos los iterators, y añadir a un hashset los resultados
		
		HashSet<Integer> hashset = new HashSet<Integer>();
		
		for (Query q : this.getQuerys() ) {
			Iterator<Integer> it = q.iterator();
			
			while (it.hasNext() ) {
				hashset.add(it.next() );
			}
		}
		
		return hashset.iterator();
		
	}

}
