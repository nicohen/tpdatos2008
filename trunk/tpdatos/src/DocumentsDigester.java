

import java.io.IOException;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

import processor.web.utils.DigesterUtils;
import dto.DocumentDto;
import dto.WordDto;
import exceptions.BusinessException;

public class DocumentsDigester {
	
	public static void main(String[] args) throws Exception {
		/*
		 * 1) Obtener lista de documentos a indexar
		 * 2) Verificar que no este en la lista de documentos ya indexados
		 * 3) Obtener el HTML
		 * 4) 
		 */
		List<DocumentDto> newDocuments = DigesterUtils.prepareNewDocuments();
		Map<Integer, String> indexedDocuments;
		try {
			indexedDocuments = DigesterUtils.prepareIndexedDocuments();
		
			for (DocumentDto document : newDocuments) {
				if (indexedDocuments.containsValue(document.getFileName()));
				List<WordDto> stopWords = DigesterUtils.prepareStopwords();
				Collections.sort(stopWords);
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
			}
		} catch (BusinessException e) {
			throw new Exception("Error procesando nuevos documentos",e);
		}
	}
	
	public void processDocument(String document, List<WordDto> stopwords) throws IOException {
		document = deleteSpecialCharacters(document);
		document = applyCaseFolding(document);
		processPipelinedStopwords(document,stopwords);
	}
	
	private void processPipelinedStopwords(String document,
			List<WordDto> stopwords) {
		StringTokenizer strTok = new StringTokenizer(document," ");
		while (strTok.hasMoreTokens()) {
			String token = strTok.nextToken();
			token = stemWord(token);
//			BPlusTreeFacade.storeWord(token);
		}
	}

	private String stemWord(String token) {
		// TODO Auto-generated method stub
		return null;
	}

	private String applyCaseFolding(String document) {
		return document.toLowerCase();
	}

	private String deleteSpecialCharacters(String document) {
		return document.replaceAll("|°¬!\"#$%&/()=?'\\¿¡´¨+-*~{}[]^`,;.:_", " ");
	}

}
