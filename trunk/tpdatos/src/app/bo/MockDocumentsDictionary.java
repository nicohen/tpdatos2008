package app.bo;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

import api.DocumentsDictionary;

import dto.DocumentDto;
import exceptions.BusinessException;

public class MockDocumentsDictionary implements DocumentsDictionary {

	private int auto_numerico = 0;
	private Map<Integer,DocumentDto > map = new HashMap<Integer,DocumentDto >();

	@Override
	public DocumentDto getDocument(Integer id) throws BusinessException {
		DocumentDto doc = map.get(id);
		
		if (doc==null) {
			throw new BusinessException("Document not found");
		}
		return doc;
	}

	private void insertDocument(Integer id, DocumentDto document)
			throws BusinessException {
		map.put(id,document);

	}

	@Override
	public Integer insertDocument(DocumentDto document) throws BusinessException {
		// TODO Auto-generated method stub
		auto_numerico ++;
		
		this.insertDocument( new Integer(auto_numerico), document);
		
		return new Integer(auto_numerico);
	}

}
