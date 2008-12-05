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
	
	private class MergeIterator implements Iterator<Integer> {
		
		private Iterator<Integer> it1, it2;
		
		Integer lastIt1, lastIt2;
		
		boolean hasNext;
		Integer next;
		
		public MergeIterator(Iterator<Integer> it1, Iterator<Integer > it2) {
			this.it1 = it1;
			this.it2 = it2;
			this.hasNext = false;
			this.next = 0;
			this.lastIt1 = 0;
			this.lastIt2 = 0;
			
			searchNext();
			
		}
		public boolean hasNext() {
			return this.hasNext;
		}
		public Integer next() {
			Integer aux = next;
			searchNext();
			return aux;
		}
		public void remove() {
			// TODO Auto-generated method stub
			
		}
		
		public void searchNext() {
			
			this.hasNext = false;
			while (true) {
				if (lastIt1 < lastIt2) {
					// obtener uno nuevo de lastIt1
					if (it1.hasNext() ) {
						this.lastIt1 = it1.next();
					} else {
						this.hasNext = false;
						break;
					}
					
				} else if (lastIt1 > lastIt2 ){
					if (it2.hasNext() ) {
						this.lastIt2 = it2.next();
					} else {
						this.hasNext = false;
						break;
					}
					
				} else {
					// ambos son 0
					if (it1.hasNext() ) {
						this.lastIt1 = it1.next();
					} else {
						this.hasNext = false;
						break;
					}
					if (it2.hasNext() ) {
						this.lastIt2 = it2.next();
					} else {
						this.hasNext = false;
						break;
					}
					
				}
				
				if (this.lastIt1.equals( this.lastIt2 ) ) {
					this.hasNext = true;
					this.next = this.lastIt1;
					break;
				}
			}
		}
	}
	
	private Iterator<Integer> mergeIterator( Iterator<Integer> it1, Iterator<Integer> it2) {
		
		return new MergeIterator(it1,it2);
	
	}

	public Iterator<Integer> iterator() {

		// generar un hashset de cada iterator, excepto para el primero
		
		List<Query> querys = this.getQuerys();
		
		if (querys.size() == 0) return new ArrayList<Integer>().iterator();
		if (querys.size() == 1) return querys.get(0).iterator();

		// componer una red de mergeIterator
		Iterator<Integer> lastIterator = null;
		for (Query q : querys ) {
			if (lastIterator == null) {
				lastIterator = q.iterator();
			} else {
				lastIterator = mergeIterator(lastIterator,q.iterator());
			}
		}
		return lastIterator;
	}


}
