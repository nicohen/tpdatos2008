package persistors;

public abstract class AbstractPersistor<E> implements Persistor<E> {

	protected int maxSize;
	
	public AbstractPersistor(int maxSize) {
		this.maxSize = maxSize;
	}
	
	@Override
	public int getDataSize(E element) {
		return this.maxSize;
	}
}
