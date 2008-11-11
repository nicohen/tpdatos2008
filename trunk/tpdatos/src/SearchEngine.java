import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;

import processor.stemming.StemmingProcessor;
import processor.stopwords.StopwordsProcessor;
import processor.utils.DigesterUtils;
import api.IQueryEngine;
import dto.DocumentDto;
import dto.DocumentsReportDto;


public class SearchEngine {

	private IQueryEngine engine;
	
	public SearchEngine( IQueryEngine pEngine) {
		this.engine = pEngine;
	}
	
	public void main(String[] args) throws Exception {
		System.out.print("Ingrese un termino a buscar: ");
		
		String word = null;
		try{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			word = br.readLine();
		}catch(IOException e) { 
			throw new Exception("Error leyendo caracteres ingresados por teclado",e);
		}

		if("".equals(word) || word==null) {
			System.out.println("El termino no puede estar vacio.");
			return;
		}
		
		long c1 = System.currentTimeMillis();
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

		//Muestro los documentos en los que aparece
		List<DocumentDto> documentsFound = engine.executeQuery(stemmedWord);
		int size = documentsFound.size();
		if(size==0) {
			System.out.println("El termino ["+word+"] no corresponde a ningun documento.");
			return;
		} else {
			System.out.println("Se encontraron "+size+" ocurrencias:");
			System.out.println("------------------------------");
			DocumentsReportDto drDto = new DocumentsReportDto();
			
			for (DocumentDto document : documentsFound) {
				drDto.setOcurrence(document);
			}
			for(DocumentDto documentResult : drDto.getOcurrences().keySet()) {
				System.out.println(drDto.getDocumentOcurrences(documentResult)+" veces en el documento "+engine.getDocumentFromId(documentResult.getDocumentId()));				
			}
		}
		long c2= System.currentTimeMillis();
		StringBuilder sb= new StringBuilder();
		sb.append((c2-c1)/1000);
		sb.append(" seg.");
		System.out.print(sb.toString());
	}
}

