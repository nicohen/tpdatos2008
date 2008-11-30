package web.indexer;
import java.io.File;
import java.util.Iterator;
import java.util.List;
import java.util.StringTokenizer;

import org.htmlparser.util.ParserException;

import processor.IndexedDocumentChecker;
import processor.stemming.StemmingProcessor;
import processor.stopwords.StopwordsProcessor;
import processor.utils.DigesterUtils;
import utils.Constants;
import utils.statistics.Statistics;
import utils.statistics.StatisticsGenerator;
import api.DefaultQueryEngine;
import api.DocumentInsert;
import api.IQueryEngine;
import api.SignatureFileQueryEngine;
import app.dao.documents.DocumentsDictionaryImp;
import dto.DocumentDto;
import dto.StopwordsPipelineDto;
import dto.WordDto;
import exceptions.BusinessException;
import exceptions.PipelineOverflowException;


public class IndexerModel {
	private StopwordsProcessor stopwordsProcessor;
	private StemmingProcessor stemmingProcessor;
	private static String SIGNATURE_FILE="signaturefile";
	private static String INDICE_INVERTIDO="indiceinvertido";
	private IQueryEngine queryEngine;
	private String path;
	
	public IndexerModel(String basePath, String method, String size) {
		this.path=basePath;
		try {
			//Inicializo las stopwords y las ordeno alfabeticamente y por cantidad de palabras ascendente
			stopwordsProcessor = new StopwordsProcessor(path+Constants.FILE_STOPWORDS);
			//Inicializo el stemmer
			stemmingProcessor = new StemmingProcessor(path+Constants.FILE_STEMMING);
			queryEngine= getQueryEngine(method, size);
			StatisticsGenerator.reset();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private IQueryEngine getQueryEngine(String method, String size) throws BusinessException{
		int blockSize= Integer.parseInt(size);
		try {
			if(SIGNATURE_FILE.equals(method)){
				return new SignatureFileQueryEngine(blockSize,path);
			}else if(INDICE_INVERTIDO.equals(method)){
				return new DefaultQueryEngine(blockSize,path);
			}
		} catch (BusinessException e) {
			throw new BusinessException("Error inicialisando motor ("+ method +").");
		}
		throw new BusinessException("Tipo de methodo ("+ method +") desconocido.");
	}
	
	public Statistics indexPath(String documentsPath) throws Exception {
		StatisticsGenerator statistics = StatisticsGenerator.getInstance();
		//Preparo los nuevos documentos a indexar
		File[] newDocuments = DocumentsDictionaryImp.prepareNewDocuments(this.path+File.separator+documentsPath);

		//Preparo los documentos que ya fueron indexados
		IndexedDocumentChecker indexedDocuments;
		try {
			indexedDocuments = queryEngine.getDocuments();
		} catch (BusinessException e) {
			throw new Exception("Error preparando nuevos documentos pendientes a indexar",e);
		}

		//Recorro los nuevos documentos a indexar
		for (int i=0;i<newDocuments.length;i++) {
			long c1 = System.currentTimeMillis();
			DocumentDto document = new DocumentDto(newDocuments[i].getName());
			//Verifico que el documento a indexar, no este dentro de los ya indexados
			if (!indexedDocuments.documentIsIndexed(document.getFileName())) {
				int totalIndexed = this.indexDocument(document);
				//Muevo el documento indexado a la carpeta de documentos indexados
				DocumentsDictionaryImp.moveFileToIndexedFolder(newDocuments[i],path+"documents/indexed");
				long c2 = System.currentTimeMillis();
				//Manejo de estadisticas por documento, seteo total de terminos y tiempos de indexacion
				statistics.addDocumentStatistics(document, totalIndexed, c2-c1);
			} else {
			}
		}
		return statistics.getStatistics();
	}
	
	public int indexDocument( DocumentDto document) throws BusinessException {
		int totalIndexed = 0;
		File inputFile = null;

		try {		
			DocumentInsert docInsert = queryEngine.prepareDocumentInsert(document.getFileName() ); 
			//Elimino tags y caracteres que no correspondan
			inputFile = new File(this.path+Constants.FOLDER_DOCUMENTS + File.separator + document.getFileName());
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
							totalIndexed++;
							stopwordsPipeline.removeWords(1);
						} else {
							//Elimino stopword encontrado en pipeline
							String eliminar = "";
							for(int j=0;j<bestWordCompare;j++) {
								eliminar+=stopwordsPipeline.getWord(j)+" ";
							}
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
