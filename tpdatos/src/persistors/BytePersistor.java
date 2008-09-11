package persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import exceptions.PersistionException;

public class BytePersistor implements Persistor<Byte>{

	public BytePersistor() {
	}

	public int getDataSize() {
		return 1;
	}

	public Byte read(DataInputStream stream) throws PersistionException {
		try {
			return stream.readByte();
		} catch (IOException e) {
			throw new PersistionException("Error Recuperando Elemento.",e);
		}
	}

	public void write(Byte element, DataOutputStream stream) throws PersistionException {
		try {
			stream.writeByte(element);
		} catch (IOException e) {
			throw new PersistionException("Error Persistiendo Elemento: "+element.toString(),e);
		}
	}

}
