package app.query.tree;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import api.query.tree.Query;

public class QueryOr extends CompositeQuery {

	@Override
	String operatorName() {
		return "or";
	}
	
	class MergeIterator implements Iterator<Integer> {
		
		private Iterator<Integer> it1, it2;
		
		Integer lastIt1, lastIt2;
		
		boolean hasNext;
		Integer next;
		Integer last;
		
		boolean it1finished, it2finished;
		
		public MergeIterator(Iterator<Integer> it1, Iterator<Integer > it2) {
			this.it1 = it1;
			this.it2 = it2;
			this.hasNext = false;
			this.next = 0;
			this.last = 0;
			this.lastIt1 = 0;
			this.lastIt2 = 0;
			this.it1finished = false;
			this.it2finished = false;
			
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
				
				if (this.it1finished ) {
					if (it2.hasNext() ) {
						if (this.lastIt2 <= last) this.lastIt2 = it2.next();
						if (this.lastIt2 > last) {
							this.next = this.lastIt2;
							this.last = next;
							this.hasNext = true;
							break;
						}
					} else {
						this.hasNext = false;
						break;
					}
				} else if (this.it1finished ) {
					if (it1.hasNext() ) {
						if (this.lastIt1 <= last) this.lastIt1 = it1.next();
						if (this.lastIt1 > last) {
							this.next = this.lastIt1;
							this.last = next;
							this.hasNext = true;
							break;
						}
					} else {
						this.hasNext = false;
						break;
					}
					
				}
				
				
				if (lastIt1 < lastIt2) {
					// obtener uno nuevo de lastIt1
					if (it1.hasNext() ) {
						this.lastIt1 = it1.next();
						if (this.lastIt1 > last) {
							this.next = this.lastIt1;
							this.last = next;
							this.hasNext = true;
							break;
						}
					} else {
						this.it1finished = true;
					}
					
				} else if ( lastIt1 > lastIt2 ) {
					if (it2.hasNext() ) {
						this.lastIt2 = it2.next();
						if (this.lastIt2 > last) {
							this.next = this.lastIt2;
							this.last = next;
							this.hasNext = true;
							break;
						}
					} else {
						this.it2finished = true;
					}
				} else {
					// son iguales
					if (it2.hasNext() ) {
						this.lastIt2 = it2.next();
					} else {
						this.it2finished = true;
					}

					if (it1.hasNext() ) {
						this.lastIt1 = it1.next();
					} else {
						this.it1finished = true;
					}
					
					if (this.it1finished) {
						if (this.it2finished) {
							this.hasNext = false;
						} else {
							if (this.lastIt2 > last ) {
							this.hasNext = true;
							this.next = this.lastIt2;
							}
						}						
					} else {
						if (this.it2finished) {
							if (this.lastIt1 > last ) {
							this.hasNext = true;
							this.next = this.lastIt1;
							}
						} else {
							// devolver el menor de ambos
							if (this.lastIt1 < this.lastIt2) {
								if (this.lastIt1 > last ) {
								this.hasNext = true;
								this.next = this.lastIt1;
								}
							} else {
								if (this.lastIt2 > last ) {
								this.hasNext = true;
								this.next = this.lastIt2;
								}
							}
						}
					}
					this.last = this.next;
					break;
				}

			}			
		}
		
	}
	

	public Iterator<Integer> iterator() {
		
		// recorrer todos los iterators, y añadir a un hashset los resultados
		
		List<Query> querys = this.getQuerys();
		
		if (querys.size() == 0) return new ArrayList<Integer>().iterator();
		if (querys.size() == 1) return querys.get(0).iterator();
		
		Iterator<Integer> lastIterator = null;
		for (Query q : querys ) {
			if (lastIterator == null) {
				lastIterator = q.iterator();
			} else {
				lastIterator = new MergeIterator(lastIterator,q.iterator());
			}
		}
		return lastIterator;

	}

}
