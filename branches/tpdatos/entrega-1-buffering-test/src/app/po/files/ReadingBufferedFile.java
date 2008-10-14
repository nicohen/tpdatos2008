package app.po.files;

import bplus.exceptions.KeyNotFoundException;
import exceptions.DataAccessException;
import exceptions.PersistanceException;
import api.po.files.Buffer;
import api.po.files.File;
import api.po.persistors.Persistor;

public class ReadingBufferedFile<E> implements File<E> {

	private File<E> file;
	private Buffer<Integer,E> buffer;
	
	public ReadingBufferedFile(File<E> file, Persistor<E> persistor) {
		this.file = file;
		this.buffer = new QueueBuffer<Integer,E>(8192, persistor);
	}
	
	public int add(E element) throws DataAccessException,
			PersistanceException {
		
		// NOTE: si add tira alguna excepcion,
		// es mejor que no se inserte el elemento en el buffer
		// tampoco
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
			E aux = buffer.get(elementId);
			/* testing */ 
			/*E retorno = file.get(elementId);
			if (!aux.equals(retorno)) {
				System.out.println("Error no son iguales");
			}*/
			
			/* testing */
			return aux;
		} catch (KeyNotFoundException e) {
		}
		E element = file.get(elementId);
		buffer.put(elementId, element);
		return element;
	}

	public int getSize() {

		return file.getSize();
	}

	public void remove(int elementId) throws DataAccessException {
		file.remove(elementId);

	}

	public int update(int elementId, E newElement)
			throws DataAccessException, PersistanceException {

		// NOTE: si update tira alguna excepcion,
		// es mejor que no se inserte el elemento en el buffer
		// tampoco
		int index = file.update(elementId, newElement);
		buffer.put(elementId, newElement);
		return index;
	}

}
