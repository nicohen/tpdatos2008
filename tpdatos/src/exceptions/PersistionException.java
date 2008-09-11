package exceptions;

public class PersistionException extends Exception {
	private static final long serialVersionUID = 1L;
	
	public PersistionException() {
		super();
	}
	
	public PersistionException(String reason) {
		super(reason);
	}

	public PersistionException(String reason, Throwable cause) {
		super(reason,cause);
	}
}
