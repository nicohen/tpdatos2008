import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
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

	public static void main(String[] args) throws BusinessException, DataAccessException, IOException {
//		String word = args[0];

		System.out.print("Ingrese un termino a buscar: ");
		String word = null;
		try{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			word = br.readLine();
		}catch(Exception e) { 
			e.printStackTrace();
		}
//		System.out.println(word); 

		if("".equals(word) || word==null) {
			System.out.println("El termino no puede estar vacio.");
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
			System.out.println("El termino ingresado ["+word+"] es un stopword, ingreselo nuevamente");
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
			System.out.println("Se encontraron "+documentsFound.size()+" ocurrencias:");
			System.out.println("------------------------------");
			for(DocumentDto documents : documentsFound) {
				System.out.println(dicc.getDocument(documents.getDocumentId()));
			}
		}

	}
}

