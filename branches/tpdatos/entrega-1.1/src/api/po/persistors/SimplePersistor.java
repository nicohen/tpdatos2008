package api.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;

import exceptions.PersistanceException;

public interface SimplePersistor<E> {
	void write(E element, DataOutputStream stream) throws PersistanceException;
	E read(DataInputStream stream) throws PersistanceException;
	public int getElementSize( E element );
}
