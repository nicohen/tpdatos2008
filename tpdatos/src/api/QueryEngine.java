package api;

import java.util.ArrayList;
import java.util.Iterator;

import dto.DocumentDto;

import api.dao.documents.DocumentsDictionary;
import app.bo.IndexImp;
import exceptions.BusinessException;

public class QueryEngine {
	private Index indice;
	private DocumentsDictionary dicc;
	public QueryEngine(Index index,DocumentsDictionary dictionary){
		dicc=dictionary;
		indice=index;
		
	}
	
	public Iterator<DocumentDto> ExecuteQuery(String consulta) throws BusinessException{
		ArrayList<DocumentDto> listaRet=new ArrayList<DocumentDto>();
		ArrayList<Integer> listaAux=new ArrayList<Integer>();
		Iterator<Integer> itAux;
		
		itAux=indice.getDocuments(consulta);
		
		while (itAux.hasNext()){
			listaRet.add(dicc.getDocument(itAux.next()));
		}
		
		return listaRet.iterator();
	}
	
}
