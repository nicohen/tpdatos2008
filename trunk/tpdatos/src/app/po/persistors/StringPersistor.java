package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;


import exceptions.PersistionException;

public class StringPersistor extends AbstractPersistor<java.lang.String> {

	public StringPersistor(int maxSize) {
		super(maxSize);
	}

	public String decode(byte[] buffer) {
		String resultado="";
		for(int i=0;(i<buffer.length && buffer[i]!=0);i++) {
			resultado+=(char)buffer[i];
		}
		return resultado;
	}

	public byte[] toBytes(String element) {
		byte[] bytes = new byte[maxSize];
		int i=0;
		for(i=0;i<element.length();i++) {
			bytes[i] = (byte)element.charAt(i);
		}
		return bytes;
	}

	public String read(DataInputStream stream) throws PersistionException {
		try {
			byte size= stream.readByte();
			StringBuffer sb= new StringBuffer();
			for(int i=0;i<size;i++){
				sb.append(stream.readChar());
			}
			return sb.toString();
		} catch (IOException e) {
			throw new PersistionException("Error recuperando elemento.",e);
		}
	}

	public void write(String element, DataOutputStream stream) throws PersistionException {
		try {
			byte size=(byte)element.length();
			stream.writeByte(size);
			for(int i=0;i<element.length();i++){
				stream.writeChar(element.charAt(i));
			}
		} catch (IOException e) {
			throw new PersistionException("Error persistiendo elemento: "+element,e);
		}
	}

}
