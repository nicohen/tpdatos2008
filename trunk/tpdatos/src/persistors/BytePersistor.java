package persistors;
import java.lang.Byte;
public class BytePersistor extends AbstractPersistor<java.lang.Byte>{

	public BytePersistor() {
		super(1);
	}
	
	public BytePersistor(int maxSize) {
		super(1);
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

}
