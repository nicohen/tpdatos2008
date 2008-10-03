import java.util.List;

import processor.stemming.StemmingProcessor;
import processor.stopwords.StopwordsProcessor;
import processor.utils.DigesterUtils;
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
		
		//Inicializo diccionario de stopwords
		StopwordsProcessor sw = new StopwordsProcessor();
		//Inicializo diccionario de stemming
		StemmingProcessor sp = new StemmingProcessor();

		//Normalizo el termino de busqueda (Case Folding, stopwords, stemming, etc)
		word = DigesterUtils.formatText(word).trim();

		String stemmedWord;
		//Chequeo que el termino ingresado no sea un stopword
		if(!sw.isStopword(word)) {
			//Aplico stemming al termino
			stemmedWord = sp.stem(word);
		} else {
			System.out.println("El termino ingresado es un stopword, ingreselo nuevamente");
			return;
		}
		
		//Realizo la consulta del termino
		IndexImp index = new IndexImp(Constants.INDEX_FILE_PATH,Constants.INDEX_FILE_SIZE);
		DocumentsDictionary dicc = new DocumentsDictionaryImp();
		QueryEngine engine = new QueryEngine(index,dicc);

		//Muestro los documentos en los que aparece
		List<DocumentDto> documentsFound = engine.executeQuery(stemmedWord);
		if(documentsFound.size()==0) {
			System.out.println("El termino ["+word+"] no corresponde a ningun documento.");
			return;
		} else {
			for(DocumentDto documents : documentsFound) {
				System.out.println(dicc.getDocument(documents.getDocumentId()));
//				System.out.println(documents.getDocumentId());
			}
		}

	}
}

