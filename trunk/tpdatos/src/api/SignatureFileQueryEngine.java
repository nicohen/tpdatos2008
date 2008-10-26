package api;

import java.util.List;

import processor.IndexedDocumentChecker;
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
		this.dicc= new DocumentsDictionaryImp();
		Persistor<SignatureFileDto> sfPersistor= new SignatureFilePersistor();
		this.signatureFiles= new RelativeFile<SignatureFileDto>(Constants.SIGNATURE_FILE_PATH,sfPersistor);
	}
	
	public List<DocumentDto> executeQuery(String consulta) throws BusinessException {
		// TODO Auto-generated method stub
		return null;
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
			this.documentSignature= new SignatureFileDto(0,0,0,0);
		}
		
		public void insertWord(String word) {
			SignatureFileDto wordSignature= SignatureUtils.getSignature(word);
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
}
