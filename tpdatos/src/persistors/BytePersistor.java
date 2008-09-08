package persistors;
public class BytePersistor implements Persistor<Byte>{

	public BytePersistor() {
	}

	public Byte decode(byte[] buffer) {
		// TODO Auto-generated method stub
		return buffer[0];
	}

	public byte[] toBytes(Byte element) {
		// TODO Auto-generated method stub
		byte[] result= new byte[1];
		result[0]=element.byteValue();
		return result;
	}

	public int getDataSize() {
		// TODO Auto-generated method stub
		return 1;
	}

}
