

import java.io.File;
import java.util.Collections;
import java.util.List;
import utils.folders.Constants;
import utils.processor.DigesterUtils;
import utils.processor.IndexedDocumentChecker;
import utils.web.HtmlUtils;
import dto.DocumentDto;
import dto.WordDto;
import exceptions.BusinessException;

public class DocumentsDigester {
	
	public static void main(String[] args) throws Exception {
		/*
		 * 1) Obtener lista de documentos a indexar
		 * 2) Verificar que no este en la lista de documentos ya indexados
		 * 3) Obtener el documento en HTML
		 * 4) 
		 * 5) 
		 */
		
		//Preparo los nuevos documentos a indexar
		File[] newDocuments = DigesterUtils.prepareNewDocuments(Constants.FOLDER_DOCUMENTS);
		DocumentDto document = null;
		
		//Inicializo las stopwords y las ordeno por cantidad de palabras y alfabeticamente
		List<WordDto> stopWords = DigesterUtils.prepareStopwords();		
		Collections.sort(stopWords);

		try {
		
			//Preparo los documentos que ya fueron indexados
			IndexedDocumentChecker indexedDocuments = DigesterUtils.prepareIndexedDocuments();

			//Recorro los nuevos documentos a indexar
			for (int i=0;i<newDocuments.length;i++) {
				document = new DocumentDto(newDocuments[i].getName());
				System.out.println("Intentando indexar documento ["+document.getFileName()+"]...");

				//Verifico que el documento a indexar, no este dentro de los ya indexados
				if (!indexedDocuments.documentIsIndexed(document.getFileName())) {
					System.out.println("Indexando documento ["+document.getFileName()+"]...");
					//Le seteo un nuevo documentId al documento a indexar
					document.setDocumentId(indexedDocuments.getNewDocumentId() );
					
					String documentText = HtmlUtils.readHtmlFile(Constants.FOLDER_DOCUMENTS+File.separator+document.getFileName());
					documentText = HtmlUtils.getHtmlBody(documentText);
					documentText = HtmlUtils.trimAllTags(documentText);
					documentText = HtmlUtils.decodeSpecialCharacters(documentText);
					System.out.println(documentText);
					
//					String last = "";
//					StringBuffer sb = null;
//					for (WordDto word : stopWords) {
//						sb = new StringBuffer();
//						sb.append(word.toString()+" ");
//						if (!last.equals(sb.toString().trim().toLowerCase())) {
//							System.out.println(sb.toString().trim().toLowerCase());
//						}
//						last = sb.toString().trim().toLowerCase();
//					}
					
					//Muevo el documento indexado a la carpeta de documentos indexados
//					DigesterUtils.moveFileToIndexed(newDocuments[i]);
					break;
				} else {
					System.out.println("El documento ["+document.getFileName()+"] ya fue indexado anteriormente");
				}
			}
		} catch (BusinessException e) {
			throw new Exception("Error preparando nuevos documentos pendientes a indexar",e);
		}
	}
/*	
	private static Integer getNewDocumentId(Map<Integer, String> indexedDocuments) {
		Set<Integer> newDocuments = indexedDocuments.keySet();
		Integer maxDocumentId = 0;
		for(Integer document : newDocuments) {
			if(document>maxDocumentId) {
				maxDocumentId = document;
			}
		}
		return (newDocuments.size()>0) ? maxDocumentId+1 : 0;
	}
*/
//	private void processDocument(String document, List<WordDto> stopwords) throws IOException {
//		document = DigesterUtils.deleteSpecialCharacters(document);
//		document = DigesterUtils.updateAcuteAndUmlaut(document);
//		processPipelinedStopwords(document,stopwords);
//	}
	
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
