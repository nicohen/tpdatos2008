package persistors;

public abstract class AbstractPersistor<E> implements Persistor<E> {

	protected int maxSize;
	
	public AbstractPersistor(int maxSize) {
		this.maxSize = maxSize;
	}

	// FIXME: no me acepta el metodo con el @override :(
	/*@Override*/
	public int getDataSize(E element) {
		return this.maxSize;
	}
}
