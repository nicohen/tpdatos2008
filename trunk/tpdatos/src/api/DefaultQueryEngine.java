package api;



import app.bo.IndexImp;
import app.bo.MockDocumentsDictionary;
import app.dao.documents.DocumentsDictionaryImp;
import exceptions.BusinessException;
import exceptions.DataAccessException;

public class DefaultQueryEngine extends QueryEngine {

	public DefaultQueryEngine() throws BusinessException, DataAccessException {
		super(	
				new IndexImp("index.bin",4096)
				,
				new DocumentsDictionaryImp()
				);
	}

}
