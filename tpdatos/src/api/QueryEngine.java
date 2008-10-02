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

	public QueryEngine(Index index,DocumentsDictionary dictionary){
		dicc=dictionary;
		indice=index;
	}
	
	public List<DocumentDto> executeQuery(String consulta) throws BusinessException{
		ArrayList<DocumentDto> listaRet=new ArrayList<DocumentDto>();
		Iterator<Integer> itAux;
		
		itAux=indice.getDocuments(consulta);
		
		while (itAux.hasNext()){
			listaRet.add(dicc.getDocument(itAux.next()));
		}
		
		return listaRet;
	}
	
}
