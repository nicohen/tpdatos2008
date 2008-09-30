package app.po.files;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import api.po.persistors.Persistor;
import exceptions.DataAccessException;
import exceptions.PersistanceException;

public class RelativeFile<E> extends AbstractFile<E> {

	public RelativeFile(String fileName, Persistor<E> persistor)
			throws DataAccessException {
		super(fileName,persistor.getDataSize(),persistor);
	}

	@Override
	public int add(E element) throws DataAccessException, PersistanceException {
		if(this.persistor.getElementSize(element)<=this.size){
			try {
				
				int index=this.length;
				long length=index*this.size;
				dataFile.seek(length);
				ByteArrayOutputStream baos= new ByteArrayOutputStream();
				DataOutputStream dos= new DataOutputStream(baos);
				persistor.write(element, dos);
				dataFile.write(baos.toByteArray());
				this.length++;
				return index;
			} catch (IOException e) {
				throw new DataAccessException("Error insertando elemento",e);
			} catch (PersistanceException e) {
				throw new DataAccessException("Error insertando elemento",e);
			}
		}else{
			throw new PersistanceException("El tamaño del elemento supera la del bloque.");
		}
	}

	@Override
	public E get(int elementId) throws DataAccessException {
		if(this.getSize()>=elementId){
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
			} catch (PersistanceException e) {
				throw new DataAccessException("Error obteniendo elemento.",e);
			}
		}else{
			throw new DataAccessException("Elemento inexistente para el [ELEMENT_ID="+elementId+"]");
		}
	}

	@Override
	public int update(int elementId, E newElement) throws DataAccessException, PersistanceException{
		if(this.persistor.getElementSize(newElement)<=this.size){
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
			} catch (PersistanceException e) {
				throw new DataAccessException("Error modificando elemento: "+newElement.toString(),e);
			}
		}else{
			throw new PersistanceException("El tamaño del elemento supera la del bloque.");
		}
	}

	@Override
	public void remove(int elementId) throws DataAccessException {
	}
}
