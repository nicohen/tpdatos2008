package app.po.files;

import java.io.IOException;

import api.po.persistors.Persistor;
import exceptions.DataAccessException;

public abstract class AbstractBloquedFile<E> extends AbstractFile<E>{
	
	protected Persistor<E> persistor;
	protected int size; // Tamano del bloque
	protected int length; // Cantidad de bloques
	
	public AbstractBloquedFile(String fileName, int size, Persistor<E> persistor)
	throws DataAccessException {
		super(fileName);
		this.persistor = persistor;
		this.size= size;
		try{
			this.length=this.getLength();
		} catch(IOException e) {
		}
	}
	
	@Override
	public int getSize() {
		return this.length;
	}
	
	private int getLength() throws IOException{
		return  (int)(this.length()/this.size);
	}
}
