package api.po.persistors;

import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.OutputStream;

import exceptions.PersistanceException;

public class SizeUtils<E> {
	
	private byte[] byteArray;
	
	public int getElementSize( Persistor<E> persistor, E element) throws PersistanceException {
		ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
		DataOutputStream outputStream = new DataOutputStream( byteArrayOutputStream );
	
		persistor.write(element, outputStream);
		
		byteArray = byteArrayOutputStream.toByteArray();
		
		return byteArray.length;
	}
	
	public void write( OutputStream outputStream ) throws IOException {
		if (outputStream != null) outputStream.write(byteArray);
	}
	
	public byte[] getByteArray() {
		return byteArray;
	}
}
