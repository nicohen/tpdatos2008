package api.po.files;

import exceptions.DataAccessException;
import exceptions.PersistanceException;

public interface File<E>{
	
	public int add(E element) throws DataAccessException, PersistanceException;
	public E get(int elementId) throws DataAccessException;
	public int update(int elementId, E newElement) throws DataAccessException,PersistanceException;
	public void remove(int elementId) throws DataAccessException;
	public void delete();
	public int getSize();
}
