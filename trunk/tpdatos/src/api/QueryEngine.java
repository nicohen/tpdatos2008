package api;

import java.util.Iterator;

import processor.IndexedDocumentChecker;
import api.dao.documents.DocumentsDictionary;
import dto.DocumentDto;
import exceptions.BusinessException;

public class QueryEngine extends AbstractQueryEngine {

	private Index indice;
	private DocumentsDictionary dicc;
	
	class NewDocumentInsert implements DocumentInsert {
		private Integer docid;
		private Index index;
		
		public NewDocumentInsert ( Integer docid, Index index ) {
			this.docid = docid;
			this.index = index;
		}
		
		public void insertWord(String word) throws BusinessException {
			index.insertWord(word, docid);
		}

		public void flush() {
			// Nada por hacer.			
		}
		
	}
	
	protected Iterator<Integer> queryWord( String word ) throws BusinessException {
		return indice.getDocumentsIterator(word);
				
	}


	protected QueryEngine(Index index,DocumentsDictionary dictionary, String path){
		
		super(path);
		dicc=dictionary;
		indice=index;
		

		
	}
	
	protected int getDocumentsCount() {
		try {
			return dicc.getDocumentsCount();
		} catch (BusinessException e) {
			// TODO Auto-generated catch block
			return 0;
		}
	}
	

//	public int countExecuteQuery(String consulta ) throws BusinessException {
//		List<DocumentDto> listaRet=new ArrayList<DocumentDto>();
//		
//		for(Integer docId : indice.getDocuments(consulta)) {
//			listaRet.add(dicc.getDocument(docId));
//		}
//
//		return listaRet.size();
//	}
	
	public DocumentInsert prepareDocumentInsert( String documento ) throws BusinessException{
		// insertar el documento en el diccionario
		
		Integer id = dicc.insertDocument(new DocumentDto(documento) );
		return new NewDocumentInsert(id, indice );
	}
	
	public IndexedDocumentChecker getDocuments() throws BusinessException {
		return dicc.getDocuments();
	}
	
	public DocumentDto getDocumentFromId( Integer id ) throws BusinessException {
		return dicc.getDocument(id);
	}
	
	protected Index getIndex() {
		return indice;
	}


	@Override
	protected DocumentDto getDocument(Integer id) throws BusinessException {
		return dicc.getDocument(id);
	}

	
}
