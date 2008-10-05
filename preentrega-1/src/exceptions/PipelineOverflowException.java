package exceptions;

public class PipelineOverflowException extends Exception {

	private static final long serialVersionUID = 1L;

	public PipelineOverflowException() {
		super();
	}
	
	public PipelineOverflowException(String reason) {
		super(reason);
	}

	public PipelineOverflowException(String reason, Throwable cause) {
		super(reason,cause);
	}
	
}
