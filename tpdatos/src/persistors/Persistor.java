package persistors;

public interface Persistor<E> {
	byte[] toBytes(E element);
	int getDataSize();
	E decode(byte[] buffer);
}
