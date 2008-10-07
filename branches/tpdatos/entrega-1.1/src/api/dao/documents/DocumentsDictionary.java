package api.dao.documents;
import processor.IndexedDocumentChecker;
import dto.DocumentDto;
import exceptions.BusinessException;


public interface DocumentsDictionary {
	
	//public void insertDocument( Integer id, DocumentDto document ) throws BusinessException;
	public Integer insertDocument( DocumentDto document ) throws BusinessException;
	public DocumentDto getDocument( Integer id ) throws BusinessException ;
	public IndexedDocumentChecker getDocuments() throws BusinessException;
}
