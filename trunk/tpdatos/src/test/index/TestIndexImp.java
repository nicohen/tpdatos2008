package test.index;

import java.util.ArrayList;
import java.util.Iterator;

import dto.DocumentDto;

import junit.framework.Assert;
import api.QueryEngine;
import api.dao.documents.DocumentsDictionary;
import app.bo.IndexImp;
import app.dao.documents.DocumentsDictionaryImp;
import exceptions.BusinessException;
import exceptions.DataAccessException;

public class TestIndexImp extends TestIndex {

	public TestIndexImp() throws BusinessException {
		//super();
	}

	@Override
	protected IndexImp createTestObject() throws BusinessException {
		return new IndexImp("index.bin", 4096) ;
	}

}
