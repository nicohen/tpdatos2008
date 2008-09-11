package api.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;

import exceptions.PersistionException;

public interface Persistor<E> {
	void write(E element, DataOutputStream stream) throws PersistionException;
	public int getDataSize();
	E read(DataInputStream stream) throws PersistionException;
}
