package app.po.persistors;

import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;

import exceptions.PersistanceException;

import api.po.persistors.Persistor;

public abstract class AbstractPersistor<E> implements Persistor<E> {

	
	@Override
	public int getElementSize(E element ) throws PersistanceException {
		
		byte[] byteArray;
		
		ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
		DataOutputStream outputStream = new DataOutputStream( byteArrayOutputStream );
	
		this.write(element, outputStream);
		
		byteArray = byteArrayOutputStream.toByteArray();
		
		return byteArray.length;		
	}
}
