package app.query.parser.exception;

public class ParserGenericException extends ParserException {

	/**
	 * 
	 */
	private static final long serialVersionUID = 6921999403983886624L;
	
	private Throwable local_cause;

	public ParserGenericException( Throwable cause ) {
		local_cause = cause;
	}
	
	public Throwable getCause() {
		return local_cause;
	}
}
