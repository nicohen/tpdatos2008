package api;



import utils.Constants;
import app.bo.IndexImp;
import app.dao.documents.DocumentsDictionaryImp;
import exceptions.BusinessException;
import exceptions.DataAccessException;

public class DefaultQueryEngine extends QueryEngine {

	public DefaultQueryEngine() throws BusinessException, DataAccessException {
		super(	
				new IndexImp(Constants.INDEX_FILE_PATH, Constants.INDEX_FILE_SIZE)
				,
				new DocumentsDictionaryImp(Constants.FILE_INDICE_INVERTIDO_INDEXED_DOCS,"document_invertido_names.txt")
				);
	}

}
