import utils.Constants;
import api.QueryEngine;
import api.dao.documents.DocumentsDictionary;
import app.bo.IndexImp;
import app.dao.documents.DocumentsDictionaryImp;
import dto.DocumentDto;
import exceptions.BusinessException;
import exceptions.DataAccessException;


public class SearchEngine {

	public static void main(String[] args) throws BusinessException, DataAccessException {
		String word = args[0];
		if("".equals(word) || word==null) {
			System.out.println("Debe ingresar un termino a buscar");
			return;
		}
		
		//Realizo la consulta del termino
		IndexImp index = new IndexImp(Constants.INDEX_FILE_PATH,Constants.INDEX_FILE_SIZE);
		DocumentsDictionary dicc = new DocumentsDictionaryImp();
		QueryEngine engine = new QueryEngine(index,dicc);

		//Muestro los documentos en los que aparece
		for(DocumentDto documents : engine.executeQuery(word)) {
			System.out.println(documents.getDocumentId());
		}

	}
}
