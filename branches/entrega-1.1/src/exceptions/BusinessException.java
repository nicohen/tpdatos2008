package exceptions;

public class BusinessException extends Exception {

	private static final long serialVersionUID = 1L;
	
	public BusinessException() {
		super();
	}
	
	public BusinessException(String reason) {
		super(reason);
	}

	public BusinessException(String reason, Throwable cause) {
		super(reason,cause);
	}

}
