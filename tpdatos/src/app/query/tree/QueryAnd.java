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
//Optimizar QueryAnd
//Stemming cuando indexa
	public Iterator<Integer> iterator() {

		// generar un hashset de cada iterator, excepto para el primero
		
		List<Query> querys = this.getQuerys();
		HashSet<Integer> resultadoMerge=new HashSet<Integer>();
		
		if (querys.size() == 0) return new HashSet<Integer>().iterator();
		if (querys.size() == 1) return querys.get(0).iterator();
		
		
		for (Query q : querys){
			Iterator<Integer> it = q.iterator();
			while(it.hasNext()){
				resultadoMerge.add(it.next());
			}
		}
		
		return resultadoMerge.iterator();
	}


}
