package app.po.persistors;

import api.po.persistors.Persistor;

public abstract class AbstractPersistor<E> implements Persistor<E> {

	protected int maxSize;
	
	public AbstractPersistor(int maxSize) {
		this.maxSize = maxSize;
	}
	
	@Override
	public int getDataSize() {
		return this.maxSize;
	}
}
