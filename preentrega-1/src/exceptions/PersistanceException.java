package exceptions;

public class PersistanceException extends Exception {
	private static final long serialVersionUID = 1L;
	
	public PersistanceException() {
		super();
	}
	
	public PersistanceException(String reason) {
		super(reason);
	}

	public PersistanceException(String reason, Throwable cause) {
		super(reason,cause);
	}
}
