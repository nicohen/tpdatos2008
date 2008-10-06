package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import api.po.persistors.Persistor;
import exceptions.PersistanceException;

public class BytePersistor implements Persistor<Byte>{

	public BytePersistor() {
	}
	@Override
	public int getDataSize() {
		return 1;
	}
	@Override
	public Byte read(DataInputStream stream) throws PersistanceException {
		try {
			return stream.readByte();
		} catch (IOException e) {
			throw new PersistanceException("Error Recuperando Elemento.",e);
		}
	}
	@Override
	public void write(Byte element, DataOutputStream stream) throws PersistanceException {
		try {
			stream.writeByte(element);
		} catch (IOException e) {
			throw new PersistanceException("Error Persistiendo Elemento: "+element.toString(),e);
		}
	}
	@Override
	public int getElementSize(Byte element) {
		return 1;
	}

}
