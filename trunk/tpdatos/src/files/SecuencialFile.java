package files;

import java.io.IOException;

import persistors.Persistor;
import exceptions.DataAccessException;

public class SecuencialFile<E> extends AbstractFile<E> {
	
	public SecuencialFile(String fileName, Persistor<E> persistor) throws DataAccessException{
		super(fileName,persistor);
	}
	
	public int add(E element) throws IOException {
		int length=(int) dataFile.length();
		dataFile.write(persistor.toBytes(element));
		return (length/persistor.getDataSize())+1;
	}

	public E get(int elementId) throws IOException {
		int offset = persistor.getDataSize()*elementId;
		byte[] buffer = new byte[persistor.getDataSize()];
		dataFile.seek(offset);
		dataFile.read(buffer);
		return persistor.decode(buffer);
	}

	public int modify(int elementId, E newElement) throws IOException {
		int offset=persistor.getDataSize()+elementId;
		dataFile.write(persistor.toBytes(newElement), offset, persistor.getDataSize());
		return elementId;
	}

	public void remove(int elementId) {
		// TODO Auto-generated method stub
		
	}

}
