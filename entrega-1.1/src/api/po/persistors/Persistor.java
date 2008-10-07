package api.po.persistors;


public interface Persistor<E> extends SimplePersistor<E>{
	public int getDataSize();
}