package api;




import java.util.ArrayList;
import java.util.Iterator;

import dto.DocumentDto;

import exceptions.BusinessException;
import app.bo.IndexImp;

public class QueryEngine {
	private IndexImp indice;
	private DocumentsDictionary dictionary;
	
	public QueryEngine(IndexImp index,DocumentsDictionary dictionary){
		indice=index;
		this.dictionary = dictionary;
	}
	
	public Iterator<DocumentDto> ExecuteQuery(String consulta) throws BusinessException{
		ArrayList<DocumentDto> listaRet=new ArrayList<DocumentDto>();
		ArrayList<Integer> listaAux=new ArrayList<Integer>();
		Iterator<Integer> itAux;
		
		itAux=indice.getDocuments(consulta);
		
		while (itAux.hasNext()){
			listaRet.add(dictionary.getDocument(itAux.next()));
		}
		
		return listaRet.iterator();
	}
	
	
	
}
