package api;

import java.util.ArrayList;
import java.util.Iterator;

import processor.IndexedDocumentChecker;

import api.dao.documents.DocumentsDictionary;
import dto.DocumentDto;
import exceptions.BusinessException;

public class QueryEngine {

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
		
	}
	

	public QueryEngine(Index index,DocumentsDictionary dictionary){
		dicc=dictionary;
		indice=index;
	}
	
	public Iterator<DocumentDto> executeQuery(String consulta) throws BusinessException{
		ArrayList<DocumentDto> listaRet=new ArrayList<DocumentDto>();
		Iterator<Integer> itAux;
		
		itAux=indice.getDocuments(consulta);
		
		while (itAux.hasNext()){
			listaRet.add(dicc.getDocument(itAux.next()));
		}
		
		return listaRet.iterator();
	}
	
	public int countExecuteQuery(String consulta ) throws BusinessException {
		ArrayList<DocumentDto> listaRet=new ArrayList<DocumentDto>();
		Iterator<Integer> itAux;
		
		itAux=indice.getDocuments(consulta);
		
		while (itAux.hasNext()){
			listaRet.add(dicc.getDocument(itAux.next()));
		}
		
		return listaRet.size();
	}
	
	public DocumentInsert prepareDocumentInsert( String documento ) throws BusinessException{
		// insertar el documento en el diccionario
		
		Integer id = dicc.insertDocument(new DocumentDto(documento) );
		return new NewDocumentInsert(id, indice );
	}
	
	public IndexedDocumentChecker getDocuments() throws BusinessException {
		return dicc.getDocuments();
	}
	
}
