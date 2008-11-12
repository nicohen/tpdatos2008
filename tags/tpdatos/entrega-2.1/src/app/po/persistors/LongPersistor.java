package app.po.persistors;

import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import api.po.persistors.Persistor;
import exceptions.PersistanceException;

public class LongPersistor implements Persistor<Long>{
	
	private int size;
	
	public LongPersistor() {
		try {
			ByteArrayOutputStream os= new ByteArrayOutputStream();
			DataOutputStream dos= new DataOutputStream(os);
			dos.writeLong(0);
			size=os.size();
		} catch (IOException e) {
			size=8;
		}
	}

	@Override
	public Long read(DataInputStream stream) throws PersistanceException {
		try {
			return stream.readLong();
		} catch (IOException e) {
			throw new PersistanceException("Error Recuperando Elemento.",e);
		}
	}

	@Override
	public void write(Long element, DataOutputStream stream) throws PersistanceException {
		try {
			stream.writeLong(element);
		} catch (IOException e) {
			throw new PersistanceException("Error Persistiendo Elemento: "+element.toString(),e);
		}
		
	}
	
	@Override
	public int getDataSize() {
		return size;
	}
	
	@Override
	public int getElementSize(Long element) {
		return getDataSize();
	}

}
