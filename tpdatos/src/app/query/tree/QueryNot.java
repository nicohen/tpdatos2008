package app.query.tree;

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

		private boolean hasNext = false;
		private Integer idActual;
		private int numDocs;
		private int lastDoc;
		private Iterator<Integer> iterator;
		
		public QueryNotIterator(Iterator<Integer> iterator, int numDocs) {
			
			this.idActual = -1;
			this.numDocs = numDocs;
			
			this.iterator = iterator;
			this.lastDoc = 0;
			
			searchNext();
						
		}
		
		private void searchNext() {
			
			while (true) {
				this.idActual++;
				
				if (this.idActual >= this.lastDoc ) {
					this.hasNext = false;
					return;
				}
				
				if (this.idActual < this.lastDoc ) {
					this.hasNext = true;
					return;
				} else {
					
					if (iterator.hasNext() ) {
						this.lastDoc = iterator.next();
					} else {
						this.lastDoc = this.numDocs; 
					}
				}
			}
			
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
