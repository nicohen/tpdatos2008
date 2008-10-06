package app.po.files;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;

import utils.statistics.StatisticsGenerator;
import utils.statistics.StatisticsGeneratorSingleton;
import api.po.persistors.Persistor;
import exceptions.DataAccessException;

public abstract class AbstractFile<E> implements api.po.files.File<E> {

	private StatisticsGenerator statistics;
	private java.io.File file;
	private RandomAccessFile dataFile;
	protected Persistor<E> persistor;
	protected int size; // Tamano del bloque
	protected int length; // Cantidad de bloques
	
	
	public AbstractFile(String fileName, int size, Persistor<E> persistor) throws DataAccessException {
		this.statistics= StatisticsGeneratorSingleton.get();
		this.persistor = persistor;
		this.size= size;
		try {
			this.file= new java.io.File(fileName);
			this.dataFile = new RandomAccessFile(this.file,"rw");
			this.length=this.getLength();
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
		return this.length;
	}
	
	private int getLength(){
		return  (int)(this.file.length()/this.size);
	}
	
	protected long length() throws IOException {
		return this.dataFile.length();
	}
	
	protected void seek( long length ) throws IOException{
		this.dataFile.seek(length);
	}

	protected void write( byte[] bytes ) throws IOException{
		statistics.addWrittenBytes(bytes.length);
		this.dataFile.write(bytes);
	}
	
	protected int read( byte[] bytes) throws IOException {
		statistics.addReadedBytes(bytes.length);
		return this.dataFile.read(bytes);
	}
	
	public void close(){
		try {
			this.dataFile.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
