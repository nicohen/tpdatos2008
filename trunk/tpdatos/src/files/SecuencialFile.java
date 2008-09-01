package files;

import java.io.IOException;

import persistors.Persistor;
import exceptions.DataAccessException;

public class SecuencialFile<E> extends AbstractFile<E> {
	
	public SecuencialFile(String fileName, int recordSize, Persistor<E> persistor) throws DataAccessException{
		super(fileName,recordSize,persistor);
	}
	
	public int add(E element) throws DataAccessException {
		try {
			int length=(int) dataFile.length();
			dataFile.seek(length);
			dataFile.write(persistor.toBytes(element));
			return (length/size)+1;
		} catch (IOException e) {
			throw new DataAccessException("Error agregando elemento.",e);			
		}
	}

	public E get(int elementId) throws DataAccessException {
		try {
			int offset = size*elementId;
			byte[] buffer = new byte[size];
			dataFile.seek(offset);
			dataFile.read(buffer);
			return persistor.decode(buffer);
		} catch (IOException e) {
			throw new DataAccessException("Error obteniendo elemento.",e);
		}
	}

	public int modify(int elementId, E newElement) throws DataAccessException {
		try {
			int offset=size+elementId;
			dataFile.write(persistor.toBytes(newElement), offset, persistor.getDataSize(newElement));
			return elementId;
		} catch (IOException e) {
			throw new DataAccessException("Error modificando elemento.",e);
		}
	}

	public void remove(int elementId) {
		// TODO Auto-generated method stub
	}

}
