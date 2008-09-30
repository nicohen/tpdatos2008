



import java.util.ArrayList;
import java.util.Iterator;

import exceptions.BusinessException;
import api.DocumentsDictionary;
import app.bo.IndexImp;

public class QueryEngine {
	private IndexImp indice;
	private DocumentsDictionary dictionary;
	
	public QueryEngine(IndexImp index,DocumentsDictionary dictionary){
		indice=index;
		this.dictionary = dictionary;
	}
	
	public Iterator<Integer> ExecuteQuery(String consulta) throws BusinessException{
		ArrayList<String> listaRet=new ArrayList<String>();
		ArrayList<Integer> listaAux=new ArrayList<Integer>();
		Iterator<Integer> itAux;
		
		itAux=indice.getDocuments(consulta);
		
		//while (itAux.hasNext()){
			//listaRet.add(Dictionary.GetStringFromId(itAux.next()));
		//}
		
		return itAux;
	}
	
	
	
}
