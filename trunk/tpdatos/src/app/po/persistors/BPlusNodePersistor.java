package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;

import api.po.persistors.Persistor;
import bplus.nodes.BPlusNode;
import exceptions.PersistanceException;

public class BPlusNodePersistor implements Persistor<BPlusNode> {

	@Override
	public int getDataSize() {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public BPlusNode read(DataInputStream stream) throws PersistanceException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void write(BPlusNode element, DataOutputStream stream)
			throws PersistanceException {
		// TODO Auto-generated method stub
	}

}
