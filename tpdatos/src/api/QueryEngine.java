package api;

import java.util.ArrayList;
import java.util.Iterator;

import exceptions.BusinessException;
import app.bo.IndexImp;

public class QueryEngine {
	private IndexImp indice;
	
	public QueryEngine(IndexImp index){
		
		indice=index;
		
	}
	
	public ArrayList<Integer> ExecuteQuery(String consulta) throws BusinessException{
		ArrayList<String> listaRet=new ArrayList<String>();
		ArrayList<Integer> listaAux=new ArrayList<Integer>();
		ArrayList<Integer> itAux;
		
		itAux=indice.getDocuments(consulta);
		
		//while (itAux.hasNext()){
			//listaRet.add(Dictionary.GetStringFromId(itAux.next()));
		//}
		
		return itAux;
	}
	
}
