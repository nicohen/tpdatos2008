package app.query.parser;

import api.query.parser.Parser;

public class QueryParser extends CompositeParser {

	public QueryParser() {
		this.add(new ParentesisParser(this) );
		this.add(new TrimParser(this) );
		this.add(new QueryOrParser(this) );
		this.add(new QueryAndParser(this) );
		this.add(new QueryNotParser(this) );
	}
	
	public void addCustomParser( Parser parser ) {
		this.add(parser);
	}

}
