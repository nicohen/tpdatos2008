package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import api.po.persistors.Persistor;
import exceptions.PersistanceException;

public class SimpleStringPersistor implements Persistor<String> {
	
	public SimpleStringPersistor() {
		super();
	}

	public String read(DataInputStream stream) throws PersistanceException {
		try {
			int i=0;
			StringBuffer sb= new StringBuffer();
			byte size= stream.readByte();
			for(;i<size;i++){
				sb.append(stream.readChar());
			}
			return sb.toString();
		} catch (IOException e) {
			throw new PersistanceException("Error recuperando elemento.",e);
		}
	}

	public void write(String element, DataOutputStream stream) throws PersistanceException {
		try {
			int i=0; //va acumulando la cantidad de bytes escritos
			byte size=(byte)element.length();
			stream.writeByte(size);
			for(i=0;i<size;i++){
				stream.writeChar(element.charAt(i));
			}
		} catch (IOException e) {
			throw new PersistanceException("Error persistiendo elemento: "+element,e);
		}
	}

	@Override
	public int getDataSize() {
		return 0;
	}

	public int getElementSize(String element) {
		return getDataSize();
	}

}
