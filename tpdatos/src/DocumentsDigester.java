

import java.io.IOException;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

import utils.processor.DigesterUtils;
import dto.DocumentDto;
import dto.WordDto;
import exceptions.BusinessException;

public class DocumentsDigester {
	
	public static void main(String[] args) throws Exception {
		/*
		 * 1) Obtener lista de documentos a indexar
		 * 2) Verificar que no este en la lista de documentos ya indexados
		 * 3) Obtener el documento en HTML
		 * 4) Obtener el body
		 */
		
		//Preparo los nuevos documentos a indexar
		List<DocumentDto> newDocuments = DigesterUtils.prepareNewDocuments();

		//Inicializo las stopwords y las ordeno por cantidad de palabras y alfabeticamente
		List<WordDto> stopWords = DigesterUtils.prepareStopwords();		
		Collections.sort(stopWords);

		try {
		
			//Preparo los documentos que ya fueron indexados
			Map<Integer, String> indexedDocuments = DigesterUtils.prepareIndexedDocuments();

			//Recorro los nuevos documentos a indexar
			for (DocumentDto document : newDocuments) {
				System.out.println("Indexando documento ["+document.getFileName()+"]");

				//Verifico que el documento a indexar, no este dentro de los ya indexados
				if (indexedDocuments.containsValue(document.getFileName())) {
					document.setDocumentId(getNewDocumentId(indexedDocuments));
					String last = "";
					StringBuffer sb = null;
					for (WordDto word : stopWords) {
						sb = new StringBuffer();
						sb.append(word.toString()+" ");
						if (!last.equals(sb.toString().trim().toLowerCase())) {
							System.out.println(sb.toString().trim().toLowerCase());
						}
						last = sb.toString().trim().toLowerCase();
					}
				} else {
					System.out.println("El documento ["+document.getFileName()+"] ya fue indexado");
				}
			}
		} catch (BusinessException e) {
			throw new Exception("Error preparando nuevos documentos pendientes a indexar",e);
		}
	}
	
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

	private void processDocument(String document, List<WordDto> stopwords) throws IOException {
		document = DigesterUtils.deleteSpecialCharacters(document);
		document = DigesterUtils.applyCaseFolding(document);
		processPipelinedStopwords(document,stopwords);
	}
	
	private void processPipelinedStopwords(String document,
			List<WordDto> stopwords) {
		StringTokenizer strTok = new StringTokenizer(document," ");
		while (strTok.hasMoreTokens()) {
			String token = strTok.nextToken();
			token = DigesterUtils.stemWord(token);
//			BPlusTreeFacade.storeWord(token);
		}
	}

}
