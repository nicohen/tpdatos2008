package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import exceptions.PersistanceException;

public class VariableStringPersistor extends MaxSizeAbstractPersistor<java.lang.String> {
	//private static char ZERO= Character.forDigit(0,2);
	public VariableStringPersistor() {
		super(0);
	}

	@Override
	public String read(DataInputStream stream) throws PersistanceException {
		try {//el string viene size+cadena
			int i=0;
			StringBuffer sb= new StringBuffer();
			byte size= (byte)stream.readByte();
			for(;i<size;i++){
				sb.append(stream.readChar());
			}
			return sb.toString();
		} catch (IOException e) {
			throw new PersistanceException("Error recuperando elemento.",e);
		}
	}
	
	@Override
	public void write(String element, DataOutputStream stream) throws PersistanceException {
		try {
			int i=0; //va acumulando la cantidad de bytes escritos
			byte size=(byte)element.length();
			stream.writeByte(size);
			for(i=0;i<size;i++){
				stream.writeChar(element.charAt(i));
			}
			// lo multiplico por 2 ya que cada char ocupa 2 bytes y le sumo 1 por el byte con la cantidad de chars
			
		} catch (IOException e) {
			throw new PersistanceException("Error persistiendo elemento: "+element,e);
		}
	}

	@Override
	public int getElementSize(String element) {
		return (element.length()*2)+1;
	}

}
