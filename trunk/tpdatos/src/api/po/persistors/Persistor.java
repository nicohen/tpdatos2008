package api.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;

import exceptions.PersistanceException;

public interface Persistor<E> {
	void write(E element, DataOutputStream stream) throws PersistanceException;
	public int getDataSize();
	E read(DataInputStream stream) throws PersistanceException;
}
