package persistors;
import java.lang.Byte;
public class BytePersistor implements Persistor<java.lang.Byte>{

	public Byte decode(byte[] buffer) {
		// TODO Auto-generated method stub
		return buffer[0];
	}

	public int getDataSize() {
		// TODO Auto-generated method stub
		return 1;
	}

	public byte[] toBytes(Byte element) {
		// TODO Auto-generated method stub
		byte[] result= new byte[1];
		result[0]=element.byteValue();
		return result;
	}

}
