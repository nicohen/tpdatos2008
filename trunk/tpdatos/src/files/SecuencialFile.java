package files;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;

import persistors.Persistor;

public class SecuencialFile<E> implements File<E> {
	
	private RandomAccessFile file;
	private Persistor<E> persistor;
	public SecuencialFile(String fileName, Persistor<E> persistor) throws FileNotFoundException{
		this.persistor=persistor;
		file= new RandomAccessFile(fileName,"rw");
	}
	public int add(E element) throws IOException {
		int length=(int) file.length();
		file.write(persistor.toBytes(element));
		return (length/persistor.getDataSize())+1;
	}

	public E get(int elementId) throws IOException {
		int offset=persistor.getDataSize()*elementId;
		byte[] buffer= new byte[persistor.getDataSize()];
		file.seek(offset);
		file.read(buffer);
		return persistor.decode(buffer);
	}

	public int modify(int elementId, E newElement) throws IOException {
		int offset=persistor.getDataSize()+elementId;
		file.write(persistor.toBytes(newElement),offset, persistor.getDataSize());
		return elementId;
	}

	public void remove(int elementId) {
		// TODO Auto-generated method stub
		
	}

}
