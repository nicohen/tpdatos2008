package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;

import dto.LinkedBlock;
import exceptions.PersistionException;

public class LinkedBlockPersistor extends AbstractPersistor<LinkedBlock> {

	public LinkedBlockPersistor(int maxSize) {
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

	
	@Override
	public void write(LinkedBlock element, DataOutputStream stream)
			throws PersistionException {
		// TODO Auto-generated method stub
		
	}

	@Override
	public LinkedBlock read(DataInputStream stream) throws PersistionException {
		// TODO Auto-generated method stub
		return null;
	}

}
