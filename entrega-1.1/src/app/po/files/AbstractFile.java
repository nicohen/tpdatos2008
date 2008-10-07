package app.po.files;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;

import utils.statistics.StatisticsGenerator;
import utils.statistics.StatisticsGeneratorSingleton;
import exceptions.DataAccessException;

public abstract class AbstractFile<E> implements api.po.files.File<E> {

	private StatisticsGenerator statistics;
	private java.io.File file;
	private RandomAccessFile dataFile;
	
	public AbstractFile(String fileName) throws DataAccessException {
		this.statistics= StatisticsGeneratorSingleton.get();
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
