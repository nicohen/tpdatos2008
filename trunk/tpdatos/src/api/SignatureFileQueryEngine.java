package api;


import java.util.ArrayList;
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
import app.dao.documents.DocumentsDictionaryImp;
import app.po.files.RelativeFile;
import app.po.persistors.SignatureFilePersistor;
import dto.DocumentDto;
import dto.SignatureFileDto;
import exceptions.BusinessException;
import exceptions.DataAccessException;


public class SignatureFileQueryEngine implements IQueryEngine{

	private DocumentsDictionary dicc;
	private File<SignatureFileDto> signatureFiles;
	
	public SignatureFileQueryEngine() throws DataAccessException{
		this.dicc= new DocumentsDictionaryImp(Constants.FILE_SIGNATURE_FILES_INDEXED_DOCS,"document_signature_names.txt");
		Persistor<SignatureFileDto> sfPersistor= new SignatureFilePersistor();
		this.signatureFiles= new RelativeFile<SignatureFileDto>(Constants.SIGNATURE_FILE_PATH,sfPersistor);
	}
	
	public List<DocumentDto> executeQuery(String consulta) throws BusinessException {
		List<DocumentDto> candidatos= new ArrayList<DocumentDto>();
		SignatureFileDto wordSignature= SignatureUtils.getSignature(consulta);
		int size= this.signatureFiles.getSize();
		try {
			for(int i=0;i<size;i++){
				SignatureFileDto documentSignature= this.signatureFiles.get(i);
				if (wordSignature.equals(SignatureUtils.AND(wordSignature, documentSignature))){
					DocumentDto dto= this.dicc.getDocument(i);
					/*
					WordCollectorQueryEngine collector = new WordCollectorQueryEngine();
					DocumentsIndexer indexer = new DocumentsIndexer(collector);
					DocumentDto document = new DocumentDto("indexed" + java.io.File.separator + dto.getFileName() );
					indexer.indexDocument(document, "");
					int ocurrencias = collector.getOcurrences(consulta);
					*/
					java.io.File input= new java.io.File(Constants.FOLDER_INDEXED,dto.getFileName());
					String texto= DigesterUtils.getFormattedHtmlFile(input);
					int ocurrencias= countMatches(texto,consulta);
					for (int j=0;j<ocurrencias;j++){
						candidatos.add(dto);
					}
				}
			}
		} catch (Exception e) {
			throw new BusinessException("Error consultando por termino: "+consulta,e);
		}
		return candidatos;
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
		return new SignatureFileDocumentInsert(id,signatureFiles);
	}
	
	class SignatureFileDocumentInsert implements DocumentInsert {
		private Integer docid;
		private File<SignatureFileDto> signatureFiles;
		private SignatureFileDto documentSignature;
		
		public SignatureFileDocumentInsert (Integer docid,File<SignatureFileDto> signatureFiles ) {
			this.docid = docid;
			this.signatureFiles= signatureFiles;
			this.documentSignature= SignatureUtils.getEmptySignature();
		}
		
		public void insertWord(String word) {
			SignatureFileDto wordSignature= SignatureUtils.getSignature(word);
			this.documentSignature= SignatureUtils.OR(documentSignature,wordSignature);
		}

		public void flush() throws BusinessException {
			try {
				this.signatureFiles.update(this.docid,this.documentSignature);
			} catch (Exception e) {
				throw new BusinessException("Error al Indexar el documento Id: "+docid,e);
			}
		}
		
	}
	
	private static boolean isEmpty(String str) {
		return str == null || str.length() == 0;
	}

	private static int countMatches(String str, String sub) {
		StemmingProcessor stemmer = new StemmingProcessor();
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
