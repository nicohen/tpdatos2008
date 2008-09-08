package files;

import java.io.IOException;

import persistors.IntegerPersistor;
import persistors.Persistor;
import exceptions.DataAccessException;

public class SecuencialFile<E> extends AbstractFile<E> {
	
	private StackFile<Integer> freeSpacesStack;
	
	public SecuencialFile(String fileName, Persistor<E> persistor) throws DataAccessException{
		super(fileName,persistor.getDataSize(),persistor);
		freeSpacesStack= new StackFile<Integer>(fileName+".fss",new IntegerPersistor());
	}
	
	public int add(E element) throws DataAccessException {
		try {
			int index=0;
			long length=0;
			try {
				index= freeSpacesStack.pop();
				length= index+size;
			}catch (DataAccessException e) {
				length= this.dataFile.length();
				index= (int) ((length/size)+1); 
			}
			dataFile.seek(length);
			dataFile.write(persistor.toBytes(element));
			return index;
		} catch (IOException e) {
			throw new DataAccessException("Error insertando elemento",e);
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
			dataFile.write(persistor.toBytes(newElement), offset, size);
			return elementId;
		} catch (IOException e) {
			throw new DataAccessException("Error modificando elemento.",e);
		}
	}

	public void remove(int elementId) throws DataAccessException {
		freeSpacesStack.push(elementId);
	}

}
