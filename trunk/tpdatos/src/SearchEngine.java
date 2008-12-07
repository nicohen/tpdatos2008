import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Iterator;

import processor.stopwords.StopwordsProcessor;
import utils.Constants;
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
		StopwordsProcessor sw = new StopwordsProcessor(Constants.FILE_STOPWORDS);
		//Inicializo diccionario de stemming
		if(!sw.isStopword(word)) {
		} else {
			System.out.println("El termino ingresado ["+word+"] es un stopword, ingreselo nuevamente");
			return;
		}
		
		//Realizo la consulta del termino

		//Muestro los documentos en los que aparece
		Iterator<DocumentDto> documentsFound = engine.iteratorQuery(word);
		
		if(!documentsFound.hasNext() ) {
			System.out.println("El termino ["+word+"] no corresponde a ningun documento.");
			return;
		} else {
			int size = 0;
			DocumentsReportDto drDto = new DocumentsReportDto();
			
			while (documentsFound.hasNext() ) {
				size++;
				DocumentDto document = documentsFound.next();
				drDto.setOcurrence(document);
			}
			for(DocumentDto documentResult : drDto.getOcurrences().keySet()) {
				System.out.println(drDto.getDocumentOcurrences(documentResult)+" veces en el documento "+engine.getDocumentFromId(documentResult.getDocumentId()));				
			}
			System.out.println("Se encontraron "+size+" ocurrencias:");
			System.out.println("------------------------------");
		}
		long c2= System.currentTimeMillis();
		StringBuilder sb= new StringBuilder();
		sb.append("Tiempo de busqueda aproximado: ").append((c2-c1) );
		sb.append(" mseg.");
		System.out.println(sb.toString());
	}
}

