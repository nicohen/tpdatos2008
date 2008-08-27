package files;

import java.io.FileNotFoundException;
import java.io.RandomAccessFile;

import exceptions.DataAccessException;

import persistors.Persistor;


public abstract class AbstractFile<E> implements File<E> {

	protected RandomAccessFile dataFile;
	protected Persistor<E> persistor;
	
	public AbstractFile(String fileName, Persistor<E> persistor) throws DataAccessException {
		this.persistor = persistor;
		try {
			this.dataFile = new RandomAccessFile(fileName,"rw");
		} catch(FileNotFoundException e) {
			throw new DataAccessException("Error construyendo archivo "+fileName,e);
		}
	}

}
