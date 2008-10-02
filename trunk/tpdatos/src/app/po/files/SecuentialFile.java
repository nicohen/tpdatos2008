package app.po.files;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import api.po.persistors.Persistor;
import exceptions.DataAccessException;
import exceptions.PersistanceException;


public class SecuentialFile<E> extends AbstractFile<E> {

	private static final int UTF_BYTE_SIZE=2;
	
	public SecuentialFile(String fileName, Persistor<E> persistor)
			throws DataAccessException {
		super(fileName,persistor.getDataSize(),persistor);
	}

	@Override
	public int add(E element) throws DataAccessException,PersistanceException {
			try {
				
				int length=(int) dataFile.length();
				dataFile.seek(length);
				ByteArrayOutputStream baos= new ByteArrayOutputStream();
				DataOutputStream dos= new DataOutputStream(baos);
				persistor.write(element, dos);
				dataFile.write(baos.toByteArray());
				return length;
			} catch (IOException e) {
				throw new DataAccessException("Error insertando elemento",e);
			} catch (PersistanceException e) {
				throw new DataAccessException("Error insertando elemento",e);
			}
		
	}

	public E getVariable(int elementId,int offset,int size) throws DataAccessException {
			try {
				byte[] buffer = new byte[size*UTF_BYTE_SIZE+1];
				dataFile.seek(offset);
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

	@Override
	public void remove(int elementId) throws DataAccessException {
	}

	@Override
	public E get(int elementId) throws DataAccessException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public int update(int elementId, E newElement) throws DataAccessException,
			PersistanceException {
		// TODO Auto-generated method stub
		return 0;
	}
}
