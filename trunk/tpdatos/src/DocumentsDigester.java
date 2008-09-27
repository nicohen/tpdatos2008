import java.io.File;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

import org.apache.log4j.Logger;
import org.htmlparser.util.ParserException;

import utils.folders.Constants;
import utils.processor.DigesterUtils;
import utils.processor.IndexedDocumentChecker;
import utils.web.HtmlUtils;
import dto.DocumentDto;
import dto.PendingWordsDto;
import dto.WordDto;
import exceptions.BusinessException;

/**
 * Clase main del proyecto donde se llaman a todas las funcionalidades iniciales
 * 
 * 1) Obtener lista de documentos a indexar
 * 2) Verificar que no este en la lista de documentos ya indexados
 * 3) Obtener el documento en HTML
 * 4) 
 * 5)
 *  
 */


public class DocumentsDigester {
	
	public static void main(String[] args) throws Exception {
		
		Logger log = Logger.getLogger(DocumentsDigester.class);
		
		//Preparo los nuevos documentos a indexar
		File[] newDocuments = DigesterUtils.prepareNewDocuments(Constants.FOLDER_DOCUMENTS);
		DocumentDto document = null;
		
		//Inicializo las stopwords y las ordeno por cantidad de palabras y alfabeticamente
		List<WordDto> stopWords = DigesterUtils.prepareStopwords();		
		Collections.sort(stopWords);
		System.out.println(stopWords.toString());

		try {
		
			//Preparo los documentos que ya fueron indexados
			IndexedDocumentChecker indexedDocuments = DigesterUtils.prepareIndexedDocuments();

			System.out.println("<<< Inicio de indexacion de documentos >>>\n");

			//Recorro los nuevos documentos a indexar
			for (int i=0;i<newDocuments.length;i++) {
				document = new DocumentDto(newDocuments[i].getName());
				log.info("---------------------------------------------------------------------");
				log.info("Intentando indexar documento ["+document.getFileName()+"]...");

				//Verifico que el documento a indexar, no este dentro de los ya indexados
				if (!indexedDocuments.documentIsIndexed(document.getFileName())) {
					log.info("Indexando documento ["+document.getFileName()+"]...");
					//Le seteo un nuevo documentId al documento a indexar
					document.setDocumentId(indexedDocuments.getNewDocumentId() );
					
					//Elimino tags y caracteres que no correspondan
					String documentText = applyHtmlFormats(document.getFileName());
					
					//Inicializo el objeto para encolar terminos 
					PendingWordsDto pendingWordsDto = new PendingWordsDto();
					
					//Recorro los terminos del documento a indexar
					StringTokenizer strTok = new StringTokenizer(documentText, " \n\t");
					while(strTok.hasMoreTokens()) {
						String token = strTok.nextToken().trim();

						//Verifico que exista el termino
						if (!"".equals(token) && token!=null) {
							token = DigesterUtils.updateAcuteAndUmlaut(token);
							token = DigesterUtils.deleteSpecialCharacters(token);
							
							for(WordDto stopWord : stopWords) {
								if(token.equals(stopWord.getWord().get(0))) {
									for(String word : stopWord.getWord()) {
										
									}
								}
							}
							
							log.info(token);
						}
					}
					
					//Muevo el documento indexado a la carpeta de documentos indexados
					//DigesterUtils.moveFileToIndexed(newDocuments[i]);
					log.info("Fin de indexacion del documento ["+document.getFileName()+"]...");
				} else {
					log.info("El documento ["+document.getFileName()+"] ya fue indexado anteriormente");
				}
			}
			
			log.info("\n<<< Fin de indexacion de documentos >>>");
		} catch (BusinessException e) {
			throw new Exception("Error preparando nuevos documentos pendientes a indexar",e);
		}
	}

	private static String applyHtmlFormats(String fileName)
			throws ParserException {
		String documentText = HtmlUtils.readHtmlFile(Constants.FOLDER_DOCUMENTS+File.separator+fileName);
		documentText = HtmlUtils.getHtmlBody(documentText);
		documentText = HtmlUtils.trimScripts(documentText);
		documentText = HtmlUtils.trimAllTags(documentText);
		return HtmlUtils.decodeSpecialCharacters(documentText);
	}

	
//	private void processPipelinedStopwords(String document,
//			List<WordDto> stopwords) {
//		StringTokenizer strTok = new StringTokenizer(document," ");
//		while (strTok.hasMoreTokens()) {
//			String token = strTok.nextToken();
//			token = DigesterUtils.stemWord(token);
////			BPlusTreeFacade.storeWord(token);
//		}
//	}

}
