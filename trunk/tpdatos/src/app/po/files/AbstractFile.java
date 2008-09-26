package app.po.files;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;

import api.po.persistors.Persistor;
import exceptions.DataAccessException;

public abstract class AbstractFile<E> implements api.po.files.File<E> {

	private java.io.File file;
	protected RandomAccessFile dataFile;
	protected Persistor<E> persistor;
	protected int size;
	
	public AbstractFile(String fileName, int size, Persistor<E> persistor) throws DataAccessException {
		this.persistor = persistor;
		this.size= size;
		try {
			this.file= new java.io.File(fileName);
			this.dataFile = new RandomAccessFile(this.file,"rw");
		} catch(FileNotFoundException e) {
			throw new DataAccessException("Error construyendo archivo "+fileName,e);
		}
	}

	@Override
	public void delete(){
		try {
			this.dataFile.close();
			this.file.delete();
		} catch (IOException e) {
			try {
				this.dataFile.setLength(0);
			} catch (IOException e1) {}
		}
		
	}
	
	@Override
	public int getSize() {
		return (int) (this.file.length()/this.size);
	}
}
