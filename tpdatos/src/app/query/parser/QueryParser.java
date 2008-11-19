package app.query.parser;

public class QueryParser extends CompositeParser {

	public QueryParser() {
	//	this.add(new QueryOrParser(this) );
		this.add(new QueryAndParser(this) );
		/*this.add(new ParentesisParser(this) );
		this.add(new TrimParser(this) );*/
		this.add(new QueryWordParser() );
	}

}
