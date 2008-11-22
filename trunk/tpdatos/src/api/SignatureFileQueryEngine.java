package api;


import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.StringTokenizer;

import processor.IndexedDocumentChecker;
import processor.stemming.StemmingProcessor;
import processor.stopwords.StopwordsProcessor;
import processor.utils.DigesterUtils;
import signaturefiles.utils.SignatureUtils;
import utils.Constants;
import api.dao.documents.DocumentsDictionary;
import api.po.files.File;
import api.po.persistors.Persistor;
import api.query.parser.Parser;
import api.query.tree.Query;
import app.dao.documents.DocumentsDictionaryImp;
import app.po.files.RelativeFile;
import app.po.persistors.SignatureFilePersistor;
import app.query.QueryWord;
import app.query.parser.QueryNotParser;
import app.query.parser.QueryParser;
import app.query.parser.QueryWordParser;
import app.query.parser.exception.ParserException;
import app.query.tree.QueryNot;
import dto.DocumentDto;
import dto.SignatureFileDto;
import exceptions.BusinessException;
import exceptions.DataAccessException;
import exceptions.PersistanceException;


public class SignatureFileQueryEngine implements IQueryEngine{

	private DocumentsDictionary dicc;
	private File<SignatureFileDto> signatureFiles;
	private int firmSize;
	private QueryParser queryParser;
		
	public SignatureFileQueryEngine(int firmSize) throws DataAccessException{
		this.dicc= new DocumentsDictionaryImp(Constants.FILE_SIGNATURE_FILES_INDEXED_DOCS,"document_signature_names.txt");
		Persistor<SignatureFileDto> sfPersistor= new SignatureFilePersistor();
		this.firmSize=firmSize;
		
		queryParser = new QueryParser();
		queryParser.addCustomParser(new DefaultQueryNotParser(queryParser) );
		queryParser.addCustomParser(new DefaultQueryWordParser() );
		
		try {
			this.signatureFiles= new RelativeFile<SignatureFileDto>(Constants.SIGNATURE_FILE_PATH,sfPersistor);
		} catch (PersistanceException e) {
			throw new DataAccessException("",e);
		}
	}
	
	
	class DefaultQueryWord extends QueryWord {

		public DefaultQueryWord(String str) {
			super(str);
		}

		public Iterator<Integer> iterator() {
			try {
				return SignatureFileQueryEngine.this.queryWord( this.getWord() );
			} catch (BusinessException e) {
					// TODO: tratar mejor la excepcion
			}
			List<Integer> lista=new ArrayList<Integer>();
			return lista.iterator();
		}
		
	}
	
	class DefaultQueryWordParser extends QueryWordParser {

		private StemmingProcessor sp;
		private StopwordsProcessor sw;
		
		public DefaultQueryWordParser()  {
			try {
				this.sp = new StemmingProcessor(Constants.FILE_STEMMING);
				//Inicializo diccionario de stopwords
				this.sw = new StopwordsProcessor(Constants.FILE_STOPWORDS);
			} catch (BusinessException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		@Override
		public QueryWord create(String unProcessedWord) {
			
			// procesar la palabra con DigesterUtils
			String word = DigesterUtils.formatText(unProcessedWord).trim();
			
			if (sw != null) {
				if ( sw.isStopword(word )) {
					// FIXME: que hacer si es un stopword ??
				}
			}
			
			if (sp != null) {
				// TODO: controlar este error
				word = sp.stem(word);
			}
			
			return new DefaultQueryWord(word);
		}
		
	}
	
	class DefaultQueryNot extends QueryNot {

		public DefaultQueryNot(Query subQuery) {
			super(subQuery);
		}

		@Override
		public int getDocumentsCount() {
			return SignatureFileQueryEngine.this.getDocumentsCount() ;
		}
		
	}
	
	class DefaultQueryNotParser extends QueryNotParser {

		public DefaultQueryNotParser(Parser recur) {
			super(recur);
		}

		@Override
		protected Query createQueryNot(Query consulta) {
			return new DefaultQueryNot(consulta);
		}
		
	}
	
	
	public List<DocumentDto> executeQuery(String consulta) throws BusinessException {
		
		try {		
			Query query = queryParser.parse(consulta);
			
			List<DocumentDto> listaRet=new ArrayList<DocumentDto>();
			Iterator<Integer> documentos = query.iterator();
			
			while (documentos.hasNext() ) { 
				Integer docId = documentos.next();
				DocumentDto dtoAux=dicc.getDocument(docId);
				dtoAux.setDocumentId(docId);
				listaRet.add(dtoAux);
			}
			
			return listaRet;
		} catch (ParserException e) {
			throw new BusinessException("Error al parsear la query", e);
		}
		
	}
	
	private int getDocumentsCount() {
		try {
			return dicc.getDocumentsCount();
		} catch (BusinessException e) {
			// TODO Auto-generated catch block
			return 0;
		}
	}
	
	public Iterator<Integer> queryWord(String word) throws BusinessException {
		List<Integer> candidatos= new ArrayList<Integer>();
		SignatureFileDto wordSignature= SignatureUtils.getSignature(word,this.firmSize);
		int size= this.signatureFiles.getSize();
		try {
			for(int i=0;i<size;i++){
				SignatureFileDto documentSignature= this.signatureFiles.get(i);
				if (wordSignature.equals(SignatureUtils.AND(wordSignature, documentSignature))){
					DocumentDto dto= this.dicc.getDocument(documentSignature.getDocumentId());

					java.io.File input= new java.io.File(Constants.FOLDER_INDEXED,dto.getFileName());
					String texto= DigesterUtils.getFormattedHtmlFile(input);
					int ocurrencias= countMatches(texto,word);
					for (int j=0;j<ocurrencias;j++){
						candidatos.add( new Integer( dto.getDocumentId() ) );
					}
				}
			}
		} catch (Exception e) {
			throw new BusinessException("Error consultando por termino: "+ word,e);
		}
		return candidatos.iterator();
	}

	public IndexedDocumentChecker getDocuments() throws BusinessException {
		return dicc.getDocuments();
	}
	
	public DocumentDto getDocumentFromId( Integer id ) throws BusinessException {
		return dicc.getDocument(id);
	}

	public DocumentInsert prepareDocumentInsert(String documento) throws BusinessException {
		// TODO Auto-generated method stub
		Integer id = dicc.insertDocument(new DocumentDto(documento));
		return new SignatureFileDocumentInsert(id,signatureFiles,firmSize);
	}
	
	class SignatureFileDocumentInsert implements DocumentInsert {
		private Integer docid;
		private File<SignatureFileDto> signatureFiles;
		private SignatureFileDto documentSignature;
		private int firmSize;
		
		public SignatureFileDocumentInsert (Integer docid,File<SignatureFileDto> signatureFiles, int firmSize ) {
			this.docid = docid;
			this.signatureFiles= signatureFiles;
			this.documentSignature= SignatureUtils.getEmptySignature(docid,firmSize);
			this.firmSize= firmSize;
		}
		
		public void insertWord(String word) {
			SignatureFileDto wordSignature= SignatureUtils.getSignature(word,firmSize);
			this.documentSignature= SignatureUtils.OR(documentSignature,wordSignature);
		}

		public void flush() throws BusinessException {
			try {
				this.signatureFiles.add(this.documentSignature);
			} catch (Exception e) {
				throw new BusinessException("Error al Indexar el documento Id: "+docid,e);
			}
		}
		
	}
	
	private static boolean isEmpty(String str) {
		return str == null || str.length() == 0;
	}

	private static int countMatches(String str, String sub) throws BusinessException {
		StemmingProcessor stemmer = new StemmingProcessor(Constants.FILE_STEMMING);
		if (isEmpty(str) || isEmpty(sub)) {
			return 0;
		}
		int count = 0;
		String nextWord;
		StringTokenizer strTok = new StringTokenizer(str, " \t\n\r\f");
		while(strTok.hasMoreTokens()) {
			nextWord = strTok.nextToken(); 
			nextWord = stemmer.stem(nextWord);
			if(sub.equals(nextWord)) {
				count++;
			}
		}
		return count;
	}
}
