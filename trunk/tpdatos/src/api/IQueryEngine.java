package api;

import java.util.Iterator;
import java.util.List;

import processor.IndexedDocumentChecker;
import dto.DocumentDto;
import exceptions.BusinessException;

public interface IQueryEngine {

	public abstract int countQuery(String consulta) 
			throws BusinessException;
	
	public abstract Iterator<DocumentDto> iteratorQuery(String consulta) throws BusinessException;

	public abstract List<DocumentDto> executeQuery(String consulta, int offset, int limit)
			throws BusinessException;

	public abstract List<DocumentDto> executeQuery(String consulta)
			throws BusinessException;
	
	public abstract DocumentInsert prepareDocumentInsert(String documento)
			throws BusinessException;

	public abstract IndexedDocumentChecker getDocuments()
			throws BusinessException;

	public abstract DocumentDto getDocumentFromId(Integer id)
			throws BusinessException;

}