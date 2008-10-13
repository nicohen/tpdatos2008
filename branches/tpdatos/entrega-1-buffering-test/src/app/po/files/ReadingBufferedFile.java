package app.po.files;

import bplus.exceptions.KeyNotFoundException;
import exceptions.DataAccessException;
import exceptions.PersistanceException;
import api.po.files.Buffer;
import api.po.files.File;

public class ReadingBufferedFile<E> implements File<E> {

	private File<E> file;
	private Buffer<Integer,E> buffer;
	
	public ReadingBufferedFile(File<E> file) {
		this.file = file;
		this.buffer = new QueueBuffer<Integer,E>(8192);
	}
	
	public int add(E element) throws DataAccessException,
			PersistanceException {
		
		int index = this.file.add(element); 
		buffer.put(index, element);
		return index;
	}

	public void close() {
		// NOTE: no necesita bajar a disco nada
		// porque solo bufferea la lectura
		file.close();

	}

	public void delete() {
		file.delete(); 

	}

	public E get(int elementId) throws DataAccessException {
		try {
			return buffer.get(elementId);
		} catch (KeyNotFoundException e) {
		}
		return file.get(elementId);
	}

	public int getSize() {

		return file.getSize();
	}

	public void remove(int elementId) throws DataAccessException {
		file.remove(elementId);

	}

	public int update(int elementId, E newElement)
			throws DataAccessException, PersistanceException {

		buffer.put(elementId, newElement);
		return file.update(elementId, newElement);
	}

}
