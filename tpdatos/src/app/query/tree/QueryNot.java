package app.query.tree;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;

import api.query.tree.Query;

public abstract class QueryNot implements Query {

	private Query subQuery;
	public QueryNot(Query subQuery) {
		this.subQuery = subQuery;
	}
	abstract public int getDocumentsCount();		
	
	public Iterator<Integer> iterator() {
		// TODO
		int cantDocs=this.getDocumentsCount();
		List<Integer> listaRet = new ArrayList<Integer> ();
		int i;
		HashSet<Integer> setAux = new HashSet<Integer>();
		
		Iterator<Integer> it = subQuery.iterator();
		
		while(it.hasNext()){
			setAux.add(it.next());
		}
		
		for (i=0;i<cantDocs;i++){
			if (setAux.add(i)) //si pudo insertar en el set entonces va en la lista
			listaRet.add(i);
		}
		return listaRet.iterator();
	}
	@Override
	public void dump(int ntabs) {
		for (int i=0;i<ntabs;i++) System.out.print("\t");
		System.out.println("not ");
		this.subQuery.dump(ntabs+1);
	}
}
