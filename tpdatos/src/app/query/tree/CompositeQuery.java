package app.query.tree;

import java.util.ArrayList;
import java.util.List;

import api.query.tree.Query;

public abstract class CompositeQuery extends AbstractQuery {
	private List<Query> querys;

	
	public CompositeQuery() {
		querys = new ArrayList<Query>();
	}
	
	public void add ( Query query ) {
		this.querys.add(query);
	}
	
	protected List<Query> getQuerys() {
		return querys;
	}
}
