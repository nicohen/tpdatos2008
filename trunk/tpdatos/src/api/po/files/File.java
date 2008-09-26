package api.po.files;

import exceptions.DataAccessException;

public interface File<E>{
	
	public int add(E element) throws DataAccessException;
	public E get(int elementId) throws DataAccessException;
	public int update(int elementId, E newElement) throws DataAccessException;
	public void remove(int elementId) throws DataAccessException;
	public void delete();
	public int getSize();
}
