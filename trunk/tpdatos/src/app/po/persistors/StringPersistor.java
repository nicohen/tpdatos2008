package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import exceptions.PersistanceException;

public class StringPersistor extends AbstractPersistor<java.lang.String> {
	private static char ZERO= Character.forDigit(0,2);
	public StringPersistor(int maxSize) {
		super(maxSize);
	}

	public String read(DataInputStream stream) throws PersistanceException {
		try {
			int i=0;
			StringBuffer sb= new StringBuffer();
			stream.readByte();
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
		if (this.maxSize<=(element.length()+1)*2){
			throw new PersistanceException("Texto demaciado largo como para persistir con este Persistor.");
		}
		try {
			int i=0; //va acumulando la cantidad de bytes escritos
			byte size=(byte)element.length();
			stream.writeByte(0);
			stream.writeByte(size);
			for(i=0;i<size;i++){
				stream.writeChar(element.charAt(i));
			}
			// lo multiplico por 2 ya que cada char ocupa 2 bytes y le sumo 1 por el byte con la cantidad de chars
			i=(i+1)*2;
			for(;i<this.maxSize;i=i+2){
				stream.writeChar(ZERO);
			}
		} catch (IOException e) {
			throw new PersistanceException("Error persistiendo elemento: "+element,e);
		}
	}

	public int getElementSize(String element) {
		return (element.length()*2)+1;
	}

}
