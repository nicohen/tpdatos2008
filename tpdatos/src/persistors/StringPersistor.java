package persistors;

public class StringPersistor extends AbstractPersistor<java.lang.String> {

	public StringPersistor(int maxSize) {
		super(maxSize);
	}

	public String decode(byte[] buffer) {
		// TODO Auto-generated method stub
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

}
