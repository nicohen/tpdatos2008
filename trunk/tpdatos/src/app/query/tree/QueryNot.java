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
		return iteratorWithHighMemoryUsage();
	}
	private class QueryNotIterator implements Iterator<Integer> {

		// FIXME, hacer el algoritmo de manera que no use el hashset
		private HashSet<Integer> setAux;
		private Integer nextDocument = 0;
		private boolean hasNext = false;
		private Integer idActual;
		private int numDocs;
		
		public QueryNotIterator(Iterator<Integer> iterator, int numDocs) {
			
			setAux = new HashSet<Integer>();
			
			while(iterator.hasNext()){
				setAux.add(iterator.next());
			}
			
			this.idActual = 0;
			this.numDocs = numDocs;
			
			searchNext();
						
		}
		
		private void searchNext() {
			for ( ; this.idActual < this.numDocs ; this.idActual++ ) {
				
				if (setAux.contains(this.idActual )) {
					// no sirve , esta en el set que estamos negando
				} else {
					hasNext = true;
					return;
					
				}
			}
			
			this.hasNext = false;
		}

		@Override
		public boolean hasNext() {
			return hasNext;
		}

		@Override
		public Integer next() {
			return this.idActual;
		}

		@Override
		public void remove() {
			// NOTE: no hay que hacer nada
			
		}
		
	}
	
	private Iterator<Integer> iteratorWithoutMemoryUsage() {

		return new QueryNotIterator( subQuery.iterator(), this.getDocumentsCount() );
			
	}
	
	private Iterator<Integer> iteratorWithHighMemoryUsage() {
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
