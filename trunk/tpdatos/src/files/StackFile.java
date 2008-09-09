package files;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;

import persistors.Persistor;
import exceptions.DataAccessException;


public class StackFile<E> implements Stack<E>{

	protected RandomAccessFile dataFile;
	protected Persistor<E> persistor;
	protected int size;
	
	public StackFile(String fileName, Persistor<E> persistor) throws DataAccessException {
		this.persistor = persistor;
		this.size= persistor.getDataSize();
		try {
			this.dataFile = new RandomAccessFile(fileName,"rw");
			dataFile.seek(dataFile.length());
		} catch(FileNotFoundException e) {
			throw new DataAccessException("Error construyendo archivo "+fileName,e);
		} catch (IOException e) {
			throw new DataAccessException("Error construyendo archivo "+fileName,e);
		}
	}
	
	public void push(E element) throws DataAccessException {
		try {
			dataFile.write(persistor.toBytes(element));
		} catch (IOException e) {
			throw new DataAccessException("Error agregando elemento.",e);			
		}
	}
	
	public E pop() throws DataAccessException {
		try {
			int length=(int) dataFile.length();
			dataFile.seek(length-size);
			byte[] buffer = new byte[size];
			dataFile.read(buffer);
			dataFile.setLength(length-size);
			return persistor.decode(buffer);
		} catch (IOException e) {
			throw new DataAccessException("Error obteniendo elemento.",e);			
		}
	}
}
