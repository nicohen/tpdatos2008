package app.po.files;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;

import api.po.files.Stack;
import api.po.persistors.Persistor;
import exceptions.DataAccessException;
import exceptions.PersistanceException;


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
			ByteArrayOutputStream baos= new ByteArrayOutputStream();
			DataOutputStream dos= new DataOutputStream(baos);
			persistor.write(element, dos);
			dataFile.write(baos.toByteArray());
		} catch (IOException e) {
			throw new DataAccessException("Error agregando elemento.",e);			
		} catch (PersistanceException e) {
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
			dataFile.read(buffer);
			ByteArrayInputStream bais= new ByteArrayInputStream(buffer);
			DataInputStream dis= new DataInputStream(bais);
			return persistor.read(dis);
		} catch (IOException e) {
			throw new DataAccessException("Error obteniendo elemento.",e);			
		} catch (PersistanceException e) {
			throw new DataAccessException("Error obteniendo elemento.",e);
		}
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
