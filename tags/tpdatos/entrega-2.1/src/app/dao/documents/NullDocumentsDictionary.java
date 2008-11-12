package app.dao.documents;

import processor.IndexedDocumentChecker;
import dto.DocumentDto;
import exceptions.BusinessException;
import api.dao.documents.DocumentsDictionary;

public class NullDocumentsDictionary implements DocumentsDictionary {

	public DocumentDto getDocument(Integer id) throws BusinessException {
		return new DocumentDto("");
	}

	public IndexedDocumentChecker getDocuments() throws BusinessException {
		return new IndexedDocumentChecker();
	}

	public Integer insertDocument(DocumentDto document) throws BusinessException {
		return 1;
	}
		
}
