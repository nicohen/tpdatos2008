package api;


import java.io.File;
import java.util.Iterator;
import java.util.List;
import java.util.StringTokenizer;

import org.apache.log4j.Logger;
import org.htmlparser.util.ParserException;

import processor.IndexedDocumentChecker;
import processor.stemming.StemmingProcessor;
import processor.stopwords.StopwordsProcessor;
import processor.utils.DigesterUtils;
import utils.Constants;
import utils.statistics.StatisticsGenerator;
import app.dao.documents.DocumentsDictionaryImp;
import dto.DocumentDto;
import dto.StopwordsPipelineDto;
import dto.WordDto;
import exceptions.BusinessException;
import exceptions.PipelineOverflowException;

/**
 * Clase main para indexar nuevos documentos
 */

public class DocumentsIndexer {
	
	private Logger log = Logger.getLogger(DocumentsIndexer.class);
	
	//Me instancio la QueryEngine para consultar los documentos existentes y nuevos
	private IQueryEngine queryEngine;
	
	private StopwordsProcessor stopwordsProcessor;
	private StemmingProcessor stemmingProcessor;

	public DocumentsIndexer(IQueryEngine pqueryEngine) throws BusinessException {
		//queryEngine = new DefaultQueryEngine();
		this.queryEngine = pqueryEngine;
		//Inicializo las stopwords y las ordeno alfabeticamente y por cantidad de palabras ascendente
		stopwordsProcessor = new StopwordsProcessor(Constants.FILE_STOPWORDS);

		//Inicializo el stemmer
		stemmingProcessor = new StemmingProcessor(Constants.FILE_STEMMING);
	}
	
	
	public int indexDocument( DocumentDto document, String logtag ) throws BusinessException {
		
		int totalIndexed = 0;
		File inputFile = null;

		try {
		
			DocumentInsert docInsert = queryEngine.prepareDocumentInsert(document.getFileName() ); 
			
			//Elimino tags y caracteres que no correspondan
			inputFile = new File(Constants.FOLDER_DOCUMENTS + File.separator + document.getFileName());
			
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
							docInsert.insertWord(indexWord);
	
							log.info(logtag+" "+document.getFileName()+"] --> [INDEXED: "+indexWord+"] [RAW WORD: "+stopwordsPipeline.getFirstWord()+"]");
	//						log.info("["+(i+1)+"/"+newDocuments.length+" "+document.getFileName()+"] --> [INDEXED: "+indexWord+"] [RAW WORD: "+stopwordsPipeline.getFirstWord()+"]");
							totalIndexed++;
							stopwordsPipeline.removeWords(1);
						} else {
							//Elimino stopword encontrado en pipeline
							String eliminar = "";
							for(int j=0;j<bestWordCompare;j++) {
								eliminar+=stopwordsPipeline.getWord(j)+" ";
							}
							log.info(logtag+" "+document.getFileName()+"] [STOPWORD: "+eliminar.trim()+"]");
							stopwordsPipeline.removeWords(bestWordCompare);
						}
	
					}
				}
			}
			docInsert.flush();
			return totalIndexed;
		
		} catch(ParserException pe) {
			throw new BusinessException("Error obteniendo HTML formateado de [FILE:"+inputFile.getAbsolutePath()+"]",pe);
		} catch(PipelineOverflowException poe) {
			throw new BusinessException("Error por overflow en el pipeline de terminos a indexar",poe);
		}

	
	}

	// indexa los documentos en un directorio
	public void indexPath( String path ) throws Exception {
		
		
		//Preparo los nuevos documentos a indexar
		File[] newDocuments = DocumentsDictionaryImp.prepareNewDocuments(path);

		//Preparo los documentos que ya fueron indexados
		IndexedDocumentChecker indexedDocuments;
		try {
			indexedDocuments = queryEngine.getDocuments();
		} catch (BusinessException e) {
			throw new Exception("Error preparando nuevos documentos pendientes a indexar",e);
		}

		log.info("<<< Inicio de indexacion de documentos >>>\n");

		//Recorro los nuevos documentos a indexar
		for (int i=0;i<newDocuments.length;i++) {

			
			long c1 = System.currentTimeMillis();
			
			DocumentDto document = new DocumentDto(newDocuments[i].getName());
			
			log.info("---------------------------------------------------------------------");
			log.info("Intentando indexar documento ["+document.getFileName()+"]");

			//Verifico que el documento a indexar, no este dentro de los ya indexados
			if (!indexedDocuments.documentIsIndexed(document.getFileName())) {
				
				int totalIndexed = this.indexDocument(document,"["+(i+1)+"/"+newDocuments.length);
				//Muevo el documento indexado a la carpeta de documentos indexados
				DocumentsDictionaryImp.moveFileToIndexedFolder(newDocuments[i],Constants.FOLDER_INDEXED);

				long c2 = System.currentTimeMillis();
				
				//Manejo de estadisticas por documento, seteo total de terminos y tiempos de indexacion
				StatisticsGenerator.getInstance().addDocumentStatistics(document, totalIndexed, c2-c1);
				
				log.info("Fin de indexacion del documento ["+document.getFileName()+"]");
			} else {
				log.info("El documento ["+document.getFileName()+"] ya fue indexado anteriormente");
			}
		}
		
		log.info("\n<<< Fin de indexacion de documentos >>>");
		
		System.out.println(StatisticsGenerator.getInstance().toString());
		
	}

	public static void main(String[] args) throws Exception {
			DocumentsIndexer indexer = new DocumentsIndexer(new SignatureFileQueryEngine(Constants.SIGNATURE_SIZE,""));
			indexer.indexPath( Constants.FOLDER_DOCUMENTS );
	}

	private int compareWords(List<String> list1, List<String> list2) {
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
