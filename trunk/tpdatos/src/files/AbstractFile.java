package files;

import java.io.FileNotFoundException;
import java.io.RandomAccessFile;

import exceptions.DataAccessException;

import persistors.Persistor;

public abstract class AbstractFile<E> implements File<E> {

	protected RandomAccessFile dataFile;
	protected Persistor<E> persistor;
	protected int size;
	
	public AbstractFile(String fileName, int size, Persistor<E> persistor) throws DataAccessException {
		this.persistor = persistor;
		this.size= size;
		try {
			this.dataFile = new RandomAccessFile(fileName,"rw");
		} catch(FileNotFoundException e) {
			throw new DataAccessException("Error construyendo archivo "+fileName,e);
		}
	}

//	@Override
//	public void delete() {
//		// TODO Auto-generated method stub
//		
//	}
}
