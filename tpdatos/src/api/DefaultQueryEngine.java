package api;



import app.bo.IndexImp;
import app.bo.MockDocumentsDictionary;
import exceptions.BusinessException;

public class DefaultQueryEngine extends QueryEngine {

	public DefaultQueryEngine() throws BusinessException {
		super(	
				new IndexImp("index.bin",4096)
				,
				new MockDocumentsDictionary()
				);
	}

}
