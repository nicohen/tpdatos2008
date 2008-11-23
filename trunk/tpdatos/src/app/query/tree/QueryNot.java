package app.query.tree;

import java.util.HashSet;
import java.util.Iterator;
import api.query.tree.Query;

public abstract class QueryNot implements Query {

	private Query subQuery;
	public QueryNot(Query subQuery) {
		this.subQuery = subQuery;
	}
	abstract public int getDocumentsCount();		
	
	public Iterator<Integer> iterator() {
		return new QueryNotIterator( subQuery.iterator(), this.getDocumentsCount() );
	}
	private class QueryNotIterator implements Iterator<Integer> {

		// FIXME, hacer el algoritmo de manera que no use el hashset
		private HashSet<Integer> setAux;
		private boolean hasNext = false;
		private Integer idActual;
		private int numDocs;
		
		public QueryNotIterator(Iterator<Integer> iterator, int numDocs) {
			
			setAux = new HashSet<Integer>();
			
			while(iterator.hasNext()){
				setAux.add(iterator.next());
			}
			
			this.idActual = -1;
			this.numDocs = numDocs;
			
			searchNext();
						
		}
		
		private void searchNext() {
			
			this.idActual++;
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
			Integer aux = this.idActual;
			searchNext();
			return aux;
		}

		@Override
		public void remove() {
			// NOTE: no hay que hacer nada
			
		}
		
	}
	
	@Override
	public void dump(int ntabs) {
		for (int i=0;i<ntabs;i++) System.out.print("\t");
		System.out.println("not ");
		this.subQuery.dump(ntabs+1);
	}
}
