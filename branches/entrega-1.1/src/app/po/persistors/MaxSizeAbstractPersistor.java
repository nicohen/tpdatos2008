package app.po.persistors;

public abstract class MaxSizeAbstractPersistor<E> extends AbstractPersistor<E> {

	protected int maxSize;
	
	public MaxSizeAbstractPersistor(int maxSize) {
		this.maxSize = maxSize;
	}
	
	@Override
	public int getDataSize() {
		return this.maxSize;
	}
	

}
