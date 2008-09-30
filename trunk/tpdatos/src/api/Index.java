package api;
import java.util.Iterator;

import exceptions.BusinessException;


public interface Index {
	public void insertWord( String word, Integer documento ) throws BusinessException ;
	public Iterator<Integer> getDocuments ( String word ) throws BusinessException;
	
	
}
