package app.query.parser;

public class QueryParser extends CompositeParser {

	public QueryParser() {
		this.add(new QueryWordParser() );
	}

}
