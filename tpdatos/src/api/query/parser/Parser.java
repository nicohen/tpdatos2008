package api.query.parser;

import api.query.tree.Query;
import app.query.parser.exception.ParserException;

public interface Parser {
		public Query parse( String str ) throws ParserException;

}
