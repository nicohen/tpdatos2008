package files;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import persistors.Persistor;
import exceptions.DataAccessException;
import exceptions.PersistionException;

public class RelativeFile<E> extends AbstractFile<E> {

	public RelativeFile(String fileName, Persistor<E> persistor)
			throws DataAccessException {
		super(fileName,persistor.getDataSize(),persistor);
	}

	@Override
	public int add(E element) throws DataAccessException {
		try {
			long length= this.dataFile.length();
			int index=(int) ((length/size)+1);
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

	@Override
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

	@Override
	public int update(int elementId, E newElement) throws DataAccessException{
		try {
			int offset=size*elementId;
			dataFile.seek(offset);
			ByteArrayOutputStream baos= new ByteArrayOutputStream();
			DataOutputStream dos= new DataOutputStream(baos);
			persistor.write(newElement, dos);
			dataFile.write(baos.toByteArray());
			return elementId;
		} catch (IOException e) {
			throw new DataAccessException("Error modificando elemento: "+newElement.toString(),e);
		} catch (PersistionException e) {
			throw new DataAccessException("Error modificando elemento: "+newElement.toString(),e);
		}
	}

	@Override
	public void remove(int elementId) throws DataAccessException {
		// TODO Auto-generated method stub

	}

}
