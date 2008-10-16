import java.io.File;
import java.util.Iterator;
import java.util.List;
import java.util.StringTokenizer;

import org.apache.log4j.Logger;

import processor.IndexedDocumentChecker;
import processor.stemming.StemmingProcessor;
import processor.stopwords.StopwordsProcessor;
import processor.utils.DigesterUtils;
import utils.Constants;
import utils.statistics.StatisticsGenerator;
import api.DefaultQueryEngine;
import api.DocumentInsert;
import api.QueryEngine;
import app.bo.IndexImp;
import app.dao.documents.DocumentsDictionaryImp;
import dto.DocumentDto;
import dto.StopwordsPipelineDto;
import dto.WordDto;
import exceptions.BusinessException;

/**
 * Clase main para indexar nuevos documentos
 */

public class DocumentsIndexer {
	
	public static void main(String[] args) throws Exception {
		
		Logger log = Logger.getLogger(DocumentsIndexer.class);
		
		//Inicializo las estadisticas
		StatisticsGenerator statistics = StatisticsGenerator.getInstance();
		
		//Me instancio un indexador de terminos para poder indexarlos
		/*IndexImp wordIndexer = new IndexImp(Constants.INDEX_FI/*LE_PATH, Constants.INDEX_FILE_SIZE) ;

		//Me instancio un DocumentsDictionary para manejar los documentos indexados
		DocumentsDictionaryImp dd = new DocumentsDictionaryImp()*/;
		
		QueryEngine queryEngine = new DefaultQueryEngine();
		
		//Preparo los nuevos documentos a indexar
		File[] newDocuments = DocumentsDictionaryImp.prepareNewDocuments(Constants.FOLDER_DOCUMENTS);
		
		//Inicializo las stopwords y las ordeno alfabeticamente y por cantidad de palabras ascendente
		StopwordsProcessor stopwordsProcessor = new StopwordsProcessor();

		//Inicializo el stemmer
		StemmingProcessor stemmingProcessor = new StemmingProcessor();

		try {
		
			//Preparo los documentos que ya fueron indexados
			IndexedDocumentChecker indexedDocuments = queryEngine.getDocuments();

			log.info("<<< Inicio de indexacion de documentos >>>\n");

			//Recorro los nuevos documentos a indexar
			for (int i=0;i<newDocuments.length;i++) {

				//Cantidad total de palabras indexadas por documento
				int totalIndexed = 0;
				
				long c1 = System.currentTimeMillis();
				
				DocumentInsert docInsert = queryEngine.prepareDocumentInsert(newDocuments[i].getName() ); 
				DocumentDto document = new DocumentDto(newDocuments[i].getName());
				
				log.info("---------------------------------------------------------------------");
				log.info("Intentando indexar documento ["+document.getFileName()+"]");

				//Verifico que el documento a indexar, no este dentro de los ya indexados
				if (!indexedDocuments.documentIsIndexed(document.getFileName())) {
					
					log.info("Indexando documento ["+document.getFileName()+"]");
					//Le seteo un nuevo documentId al documento a indexar
					document.setDocumentId(indexedDocuments.getNewDocumentId() );
					
					//Elimino tags y caracteres que no correspondan
					File inputFile = new File(Constants.FOLDER_DOCUMENTS + File.separator + document.getFileName());
					String documentText = DigesterUtils.getFormattedHtmlFile(inputFile);
					
					//Inicializo el pipeline para encolar terminos 
					StopwordsPipelineDto stopwordsPipeline = new StopwordsPipelineDto();
					
					//Me inicializo un tokenizer para recorrer los terminos del documento
					StringTokenizer strTok = new StringTokenizer(documentText, " \t\n\r\f");

					//Hago un preload de terminos en el pipeline
					while(strTok.hasMoreTokens() && stopwordsPipeline.getSize()<(stopwordsPipeline.getMaxSize()-1)) {
						String token = (strTok.nextToken()).trim();
						if (!"".equals(token) && token!=null) {
							stopwordsPipeline.addWord(token);
						}
					}
					
					while(strTok.hasMoreTokens() || !stopwordsPipeline.isEmpty()) {
						
						boolean hasMoreTokens = false;
						String token = null;
						if(strTok.hasMoreTokens()) {
							 token = (strTok.nextToken()).trim();
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
								for(WordDto stopword : stopwordsProcessor.getStopwords()) {
	
									wordCompare = compareWords(stopwordsPipeline.getWords(),stopword.getWord());
									
									if(wordCompare>bestWordCompare) {
										bestWordCompare = wordCompare;
									}
									
									if(bestWordCompare>0 && wordCompare<bestWordCompare) {
										break;
									}
									
								}
								
								if(bestWordCompare==0) {
									//El primer termino del pipeline no es stopword, por lo tanto se indexa
										String indexWord = stemmingProcessor.stem(stopwordsPipeline.getFirstWord());
//									wordIndexer.insertWord(indexWord, document.getDocumentId());
									docInsert.insertWord(indexWord);
									
									log.info("["+(i+1)+"/"+newDocuments.length+" "+document.getFileName()+"] --> [INDEXED: "+indexWord+"] [RAW WORD: "+stopwordsPipeline.getFirstWord()+"]");
									totalIndexed++;
									stopwordsPipeline.removeWords(1);
								} else {
									//Elimino stopword encontrado en pipeline
									String eliminar = "";
									for(int j=0;j<bestWordCompare;j++) {
										eliminar+=stopwordsPipeline.getWord(j)+" ";
									}
									log.info("["+(i+1)+"/"+newDocuments.length+" "+document.getFileName()+"] [STOPWORD: "+eliminar.trim()+"]");
									stopwordsPipeline.removeWords(bestWordCompare);
								}

							}
						}
					}
					
					//Seteo el documento como indexado
					//indexedDocuments.addDocument(dd.insertDocument(document), document.getFileName());
					
					//Muevo el documento indexado a la carpeta de documentos indexados
					DocumentsDictionaryImp.moveFileToIndexedFolder(newDocuments[i]);

					long c2 = System.currentTimeMillis();
					
					statistics.addDocumentStatistics(document, totalIndexed, c2-c1);
					
					log.info("Fin de indexacion del documento ["+document.getFileName()+"]");
				} else {
					log.info("El documento ["+document.getFileName()+"] ya fue indexado anteriormente");
				}
			}
			
			log.info("\n<<< Fin de indexacion de documentos >>>");
			
			System.out.println(statistics.toString());
			
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