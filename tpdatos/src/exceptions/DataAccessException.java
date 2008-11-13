package exceptions;

public class DataAccessException extends BusinessException {
	
	private static final long serialVersionUID = 1L;
	
	public DataAccessException() {
		super();
	}
	
	public DataAccessException(String reason) {
		super(reason);
	}

	public DataAccessException(String reason, Throwable cause) {
		super(reason,cause);
	}

}
