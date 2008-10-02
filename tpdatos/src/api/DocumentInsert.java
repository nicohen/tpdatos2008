package api;

import exceptions.BusinessException;

// realiza inserts de terminos sobre un documento
public interface DocumentInsert {
	
	public void insertWord(String word) throws BusinessException;
	
}
