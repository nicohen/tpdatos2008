package persistors;

public interface Persistor<E> {
	byte[] toBytes(E element);
	public int getDataSize();
	E decode(byte[] buffer);
}
