package persistors;

public interface Persistor<E> {
	byte[] toBytes(E element);
	int getDataSize(E element);
	E decode(byte[] buffer);
}
