package api;
import java.util.Iterator;
import java.util.List;

import exceptions.BusinessException;


public interface Index {
	public void insertWord( String word, Integer documento ) throws BusinessException ;
	public List<Integer> getDocuments ( String word ) throws BusinessException;	
	public Iterator<Integer> getDocumentsIterator ( String word ) throws BusinessException;
}
