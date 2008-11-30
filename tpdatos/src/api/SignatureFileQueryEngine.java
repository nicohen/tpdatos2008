package api;


import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.StringTokenizer;

import processor.IndexedDocumentChecker;
import processor.stemming.StemmingProcessor;
import processor.utils.DigesterUtils;
import signaturefiles.utils.SignatureUtils;
import utils.Constants;
import api.dao.documents.DocumentsDictionary;
import api.po.files.File;
import api.po.persistors.Persistor;
import api.query.tree.Query;
import app.dao.documents.DocumentsDictionaryImp;
import app.po.files.RelativeFile;
import app.po.persistors.SignatureFilePersistor;
import app.query.parser.QueryParser;
import app.query.parser.exception.ParserException;
import dto.DocumentDto;
import dto.SignatureFileDto;
import exceptions.BusinessException;
import exceptions.DataAccessException;
import exceptions.PersistanceException;


public class SignatureFileQueryEngine extends AbstractQueryEngine{

	private DocumentsDictionary dicc;
	private File<SignatureFileDto> signatureFiles;
	private int firmSize;
	private QueryParser queryParser;
	private String basePath;
		
	public SignatureFileQueryEngine(int firmSize, String basePath) throws DataAccessException{
		super(basePath);
		this.basePath= basePath;
		this.dicc= new DocumentsDictionaryImp(basePath+Constants.FILE_SIGNATURE_FILES_INDEXED_DOCS,basePath+"document_signature_names.txt");
		Persistor<SignatureFileDto> sfPersistor= new SignatureFilePersistor();
		this.firmSize=firmSize;
		
		queryParser = new QueryParser();
		queryParser.addCustomParser(new DefaultQueryNotParser(queryParser) );
		queryParser.addCustomParser(new DefaultQueryWordParser(basePath) );
		
		try {
			this.signatureFiles= new RelativeFile<SignatureFileDto>(basePath+Constants.SIGNATURE_FILE_PATH,sfPersistor);
		} catch (PersistanceException e) {
			throw new DataAccessException("",e);
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
	
	protected int getDocumentsCount() {
		try {
			return dicc.getDocumentsCount();
		} catch (BusinessException e) {
			// TODO Auto-generated catch block
			return 0;
		}
	}
	
	protected Iterator<Integer> queryWord(String word) throws BusinessException {
		List<Integer> candidatos= new ArrayList<Integer>();

		word = processWord(word);

		SignatureFileDto wordSignature= SignatureUtils.getSignature(word,this.firmSize);
		int size= this.signatureFiles.getSize();
		try {
			for(int i=0;i<size;i++){
				SignatureFileDto documentSignature= this.signatureFiles.get(i);
				if (wordSignature.equals(SignatureUtils.AND(wordSignature, documentSignature))){

					DocumentDto dto= this.dicc.getDocument(i);
					
//					WordCollectorQueryEngine collector = new WordCollectorQueryEngine(word);
//					DocumentsIndexer indexer = new DocumentsIndexer(collector);
//					
//					
//					DocumentDto document = new DocumentDto(basePath+Constants.SUBFOLDER_INDEXED + java.io.File.separator + dto.getFileName() );
//					
//					indexer.indexDocument(document, "");
//					int ocurrencias = collector.getOcurrences();

					java.io.File input= new java.io.File(this.basePath+Constants.FOLDER_INDEXED,dto.getFileName());
					String texto= DigesterUtils.getFormattedHtmlFile(input);
					int ocurrencias= countMatches(texto,word,basePath);
					
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

	private static int countMatches(String str, String sub, String path) throws BusinessException {
		StemmingProcessor stemmer = new StemmingProcessor(path+Constants.FILE_STEMMING);
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

	@Override
	protected DocumentDto getDocument(Integer id) throws BusinessException {
		return dicc.getDocument(id);
	}
}
