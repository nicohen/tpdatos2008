package app.po.files;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import api.po.persistors.Persistor;
import app.po.persistors.IntegerPersistor;
import exceptions.DataAccessException;
import exceptions.PersistanceException;

public class SecuencialFile<E> extends AbstractBloquedFile<E> {
	
	private StackFile<Integer> freeSpacesStack;
	private static final byte REMOVED_ELEMENT= (byte) 0xFF;
	private static final byte VALID_ELEMENT= (byte) 0x00;
	
	public SecuencialFile(String fileName, Persistor<E> persistor) throws DataAccessException, PersistanceException{
		super(fileName,persistor.getDataSize()+1,persistor);
		freeSpacesStack= new StackFile<Integer>(fileName+".fss",new IntegerPersistor());
	}
	
	public int add(E element) throws DataAccessException {
		try {
			int index=0;
			long length=0;
			try {
				index= freeSpacesStack.pop();
			}catch (DataAccessException e) {
				index= this.length; 
			}
			length= index*size;
			/*dataFile.*/seek(length);
			ByteArrayOutputStream baos= new ByteArrayOutputStream();
			DataOutputStream dos= new DataOutputStream(baos);
			dos.writeByte(VALID_ELEMENT);
			persistor.write(element, dos);
			/*dataFile.*/write(baos.toByteArray());
			this.length++;
			return index;
		} catch (IOException e) {
			throw new DataAccessException("Error insertando elemento",e);
		} catch (PersistanceException e) {
			throw new DataAccessException("Error insertando elemento",e);
		}
	}
	
	

	public E get(int elementId) throws DataAccessException {
		try {
			int offset = size*elementId;
			byte[] buffer = new byte[size];
			/*dataFile.*/seek(offset);
			/*dataFile.*/read(buffer);
			ByteArrayInputStream bais= new ByteArrayInputStream(buffer);
			DataInputStream dis= new DataInputStream(bais);
			byte flag=dis.readByte();
			if (flag==VALID_ELEMENT){
				return persistor.read(dis);
			}else{
				return null;
			}
			
		} catch (IOException e) {
			throw new DataAccessException("Error obteniendo elemento.",e);
		} catch (PersistanceException e) {
			throw new DataAccessException("Error obteniendo elemento.",e);
		}
	}

	public int update(int elementId, E newElement) throws DataAccessException {
		try {
			int offset=size*elementId;
			/*dataFile.*/seek(offset);
			ByteArrayOutputStream baos= new ByteArrayOutputStream();
			DataOutputStream dos= new DataOutputStream(baos);
			dos.writeByte(VALID_ELEMENT);
			persistor.write(newElement, dos);
			/*dataFile.*/write(baos.toByteArray());
			return elementId;
		} catch (IOException e) {
			throw new DataAccessException("Error modificando elemento.",e);
		} catch (PersistanceException e) {
			throw new DataAccessException("Error modificando elemento.",e);
		}
	}

	public void remove(int elementId) throws DataAccessException {
		try {
			int offset=size*elementId;
			/*dataFile.*/seek(offset);
			ByteArrayOutputStream baos= new ByteArrayOutputStream();
			DataOutputStream dos= new DataOutputStream(baos);
			dos.writeByte(REMOVED_ELEMENT);
			/*dataFile.*/write(baos.toByteArray());
			freeSpacesStack.push(elementId);
		} catch (IOException e) {
			throw new DataAccessException("Error modificando elemento.",e);
		}
	}

	public void close(){
		this.freeSpacesStack.close();
		super.close();
	}
}
