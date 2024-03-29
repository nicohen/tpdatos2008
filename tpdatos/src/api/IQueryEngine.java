package api;

import java.util.Iterator;

import processor.IndexedDocumentChecker;
import dto.DocumentDto;
import exceptions.BusinessException;

public interface IQueryEngine {

	public abstract int countQuery(String consulta) 
			throws BusinessException;
	
	public abstract Iterator<DocumentDto> iteratorQuery(String consulta) throws BusinessException;
	
	public abstract DocumentInsert prepareDocumentInsert(String documento)
			throws BusinessException;

	public abstract IndexedDocumentChecker getDocuments()
			throws BusinessException;

	public abstract DocumentDto getDocumentFromId(Integer id)
			throws BusinessException;

}