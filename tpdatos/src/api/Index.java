package api;
import java.util.List;

import exceptions.BusinessException;


public interface Index {
	public void insertWord( String word, Integer documento ) throws BusinessException ;
	public List<Integer> getDocuments ( String word ) throws BusinessException;	
}
