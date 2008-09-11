package app.po.files;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import api.po.persistors.Persistor;
import app.po.persistors.IntegerPersistor;

import exceptions.DataAccessException;
import exceptions.PersistionException;

public class SecuencialFile<E> extends AbstractFile<E> {
	
	private StackFile<Integer> freeSpacesStack;
	
	public SecuencialFile(String fileName, Persistor<E> persistor) throws DataAccessException{
		super(fileName,persistor.getDataSize(),persistor);
		freeSpacesStack= new StackFile<Integer>(fileName+".fss",new IntegerPersistor());
	}
	
	public int add(E element) throws DataAccessException {
		try {
			int index=0;
			long length=0;
			try {
				index= freeSpacesStack.pop();
				length= index+size;
			}catch (DataAccessException e) {
				length= this.dataFile.length();
				index= (int) ((length/size)+1); 
			}
			dataFile.seek(length);
			ByteArrayOutputStream baos= new ByteArrayOutputStream();
			DataOutputStream dos= new DataOutputStream(baos);
			persistor.write(element, dos);
			dataFile.write(baos.toByteArray());
			return index;
		} catch (IOException e) {
			throw new DataAccessException("Error insertando elemento",e);
		} catch (PersistionException e) {
			throw new DataAccessException("Error insertando elemento",e);
		}
	}
	
	

	public E get(int elementId) throws DataAccessException {
		try {
			int offset = size*elementId;
			byte[] buffer = new byte[size];
			dataFile.seek(offset);
			dataFile.read(buffer);
			ByteArrayInputStream bais= new ByteArrayInputStream(buffer);
			DataInputStream dis= new DataInputStream(bais);
			return persistor.read(dis);
		} catch (IOException e) {
			throw new DataAccessException("Error obteniendo elemento.",e);
		} catch (PersistionException e) {
			throw new DataAccessException("Error obteniendo elemento.",e);
		}
	}

	public int update(int elementId, E newElement) throws DataAccessException {
		try {
			int offset=size*elementId;
			dataFile.seek(offset);
			ByteArrayOutputStream baos= new ByteArrayOutputStream();
			DataOutputStream dos= new DataOutputStream(baos);
			persistor.write(newElement, dos);
			dataFile.write(baos.toByteArray());
			return elementId;
		} catch (IOException e) {
			throw new DataAccessException("Error modificando elemento.",e);
		} catch (PersistionException e) {
			throw new DataAccessException("Error modificando elemento.",e);
		}
	}

	public void remove(int elementId) throws DataAccessException {
		freeSpacesStack.push(elementId);
	}

}
