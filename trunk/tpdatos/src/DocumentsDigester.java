import java.io.File;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.StringTokenizer;

import org.apache.log4j.Logger;

import processor.IndexedDocumentChecker;
import processor.stemming.StemmingProcessor;
import processor.utils.DigesterUtils;
import utils.Constants;
import app.bo.IndexImp;
import dto.DocumentDto;
import dto.StopwordsPipelineDto;
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
		
		IndexImp wordIndexer = new IndexImp(Constants.INDEX_FILE_PATH, Constants.INDEX_FILE_SIZE) ;
//		QueryEngine engine=new QueryEngine(index);
		
		//Preparo los nuevos documentos a indexar
		File[] newDocuments = DigesterUtils.prepareNewDocuments(Constants.FOLDER_DOCUMENTS);
		DocumentDto document = null;
		
		//Inicializo las stopwords y las ordeno por cantidad de palabras y alfabeticamente
		List<WordDto> stopWords = DigesterUtils.prepareStopwords();		
		Collections.sort(stopWords);
//		log.info(stopWords.toString());
		
		try {
		
			//Preparo los documentos que ya fueron indexados
			IndexedDocumentChecker indexedDocuments = DigesterUtils.prepareIndexedDocuments();

			log.info("<<< Inicio de indexacion de documentos >>>\n");

			//Recorro los nuevos documentos a indexar
			for (int i=0;i<newDocuments.length;i++) {
				document = new DocumentDto(newDocuments[i].getName());
				log.info("---------------------------------------------------------------------");
				log.info("Intentando indexar documento ["+document.getFileName()+"]");

				//Verifico que el documento a indexar, no este dentro de los ya indexados
				if (!indexedDocuments.documentIsIndexed(document.getFileName())) {
					
					log.info("Indexando documento ["+document.getFileName()+"]");
					//Le seteo un nuevo documentId al documento a indexar
					document.setDocumentId(indexedDocuments.getNewDocumentId() );
					
					//Elimino tags y caracteres que no correspondan
					File inputFile = new File(Constants.FOLDER_DOCUMENTS + File.separator + document.getFileName());
					String documentText = DigesterUtils.getFormatedHtmlFile(inputFile);
					
					//Inicializo el objeto para encolar terminos 
					StopwordsPipelineDto stopwordsPipeline = new StopwordsPipelineDto();
					
					//Inicializo el stemmer
					StemmingProcessor stemmer = new StemmingProcessor();
					
					//Me inicializo un tokenizer para recorrer los terminos del documento
					StringTokenizer strTok = new StringTokenizer(documentText, " \n\t");

					//Hago un preload de terminos en el pipeline
					while(strTok.hasMoreTokens() && stopwordsPipeline.getSize()<(stopwordsPipeline.getMaxSize()-1)) {
						String token = strTok.nextToken().trim();
						if (!"".equals(token) && token!=null) {
							stopwordsPipeline.addWord(token);
						}
					}
					
					while(strTok.hasMoreTokens() || !stopwordsPipeline.isEmpty()) {
						
						boolean hasMoreTokens = false;
						String token = null;
						if(strTok.hasMoreTokens()) {
							 token = strTok.nextToken().trim();
							 hasMoreTokens = true;
						}

						//Verifico que exista el termino
						if ((!"".equals(token) && token!=null) || !hasMoreTokens) {
							
							if(hasMoreTokens) {
								stopwordsPipeline.addWord(token);
							}

							if(stopwordsPipeline.isFull() || !hasMoreTokens) {
								
								int bestWordCompare = 0;
								int wordCompare = 0;
								//Recorro los stopwords y verifico si el/los termino/s son un stopword
								for(WordDto stopword : stopWords) {
	
									wordCompare = compareWords(stopwordsPipeline.getWords(),stopword.getWord());
									
									if(wordCompare>bestWordCompare) {
										bestWordCompare = wordCompare;
									}
									
									if(bestWordCompare>0 && wordCompare<bestWordCompare) {
										break;
									}
									
								}
								
								if(bestWordCompare==0) {
									//El primer termino del pipeline no es stopword
									String indexWord = stemmer.stem(stopwordsPipeline.getFirstWord());
									log.info("[### AGREGADA ###] --> "+indexWord);
									wordIndexer.insertWord(indexWord, document.getDocumentId());
									stopwordsPipeline.removeWords(1);
								} else {
									String eliminar = "";
									for(int j=0;j<bestWordCompare;j++) {
										eliminar+=stopwordsPipeline.getWord(j)+" ";
									}
									log.info("\t[### EXCLUIDA ###] --> "+eliminar.trim());
									stopwordsPipeline.removeWords(bestWordCompare);
								}

							}
						}
					}
					
					//Muevo el documento indexado a la carpeta de documentos indexados
//					DigesterUtils.moveFileToIndexedFolder(newDocuments[i]);

					log.info("Fin de indexacion del documento ["+document.getFileName()+"]");
				} else {
					log.info("El documento ["+document.getFileName()+"] ya fue indexado anteriormente");
				}
			}
			
			log.info("\n<<< Fin de indexacion de documentos >>>");
			
		} catch (BusinessException e) {
			throw new Exception("Error preparando nuevos documentos pendientes a indexar",e);
		}
	}

	private static int compareWords(List<String> list1, List<String> list2) {
		int qtyMatch = 0;
		Iterator<String> it1 = list1.iterator();
		Iterator<String> it2 = list2.iterator();
		while(it1.hasNext() && it2.hasNext()) {
			if (it1.next().compareTo(it2.next())==0) {
				qtyMatch++;
			} else {
				return qtyMatch;
			}
		}
		return qtyMatch;
	}


}
