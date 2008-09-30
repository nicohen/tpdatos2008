package api.bo;
import java.util.ArrayList;
import java.util.Iterator;

import exceptions.BusinessException;


public interface Index {
	public void insertWord( String word, Integer documento ) throws BusinessException ;
	public ArrayList<Integer> getDocuments ( String word ) throws BusinessException;
	
	
}
