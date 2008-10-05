package api;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

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
	
	public List<DocumentDto> executeQuery(String consulta) throws BusinessException{
		ArrayList<DocumentDto> listaRet=new ArrayList<DocumentDto>();
		Iterator<Integer> itAux;
		
		itAux=indice.getDocuments(consulta);
		
		while (itAux.hasNext()){
			listaRet.add(dicc.getDocument(itAux.next()-1));
		}
		
		return listaRet;
	}
	
	public DocumentInsert prepareDocumentInsert( String documento ) throws BusinessException{
		// insertar el documento en el diccionario
		
		Integer id = dicc.insertDocument(new DocumentDto(documento) );
		return new NewDocumentInsert(id, indice );
	}
	
	
}
