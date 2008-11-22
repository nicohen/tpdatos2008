package app.query.tree;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import api.query.tree.Query;

abstract public class AbstractQuery implements Query {

	public Iterator<Integer> getIterator() {
		return this.execute().iterator();
	}
	
}
