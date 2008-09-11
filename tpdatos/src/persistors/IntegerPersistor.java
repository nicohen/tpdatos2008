package persistors;

import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import exceptions.PersistionException;

public class IntegerPersistor implements Persistor<Integer>{
	
	private int size;
	
	public IntegerPersistor() {
		try {
			ByteArrayOutputStream os= new ByteArrayOutputStream();
			DataOutputStream dos= new DataOutputStream(os);
			dos.writeInt(0);
			size=os.size();
		} catch (IOException e) {
			size=4;
		}
	}

	public Integer read(DataInputStream stream) throws PersistionException {
		try {
			return stream.readInt();
		} catch (IOException e) {
			throw new PersistionException("Error Recuperando Elemento.",e);
		}
	}

	public void write(Integer element, DataOutputStream stream) throws PersistionException {
		try {
			stream.writeInt(element);
		} catch (IOException e) {
			throw new PersistionException("Error Persistiendo Elemento: "+element.toString(),e);
		}
		
	}

	public int getDataSize() {
		return size;
	}

}
