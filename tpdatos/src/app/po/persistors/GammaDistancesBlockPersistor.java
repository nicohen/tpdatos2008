package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import exceptions.PersistanceException;
import linkedblocks.codification.GammaDistancesBlock;
import api.po.persistors.Persistor;

public class GammaDistancesBlockPersistor implements
		Persistor<GammaDistancesBlock> {

	
	private int dataSize;

	public GammaDistancesBlockPersistor( int dataSize ) {
		this.dataSize = dataSize;
	}
	
	public int getDataSize() {
		return dataSize;
	}

	public int getElementSize(GammaDistancesBlock element) {
		return element.toByteArray().length;
	}

	public GammaDistancesBlock read(DataInputStream stream) throws PersistanceException {
		byte[] arry = new byte[dataSize];
		try {
			stream.read(arry);
			return new GammaDistancesBlock(dataSize,arry);
		} catch (IOException e) {
			throw new PersistanceException("i/o error",e);
		}
 
	}

	public void write(GammaDistancesBlock element, DataOutputStream stream) throws PersistanceException {
		try {
			stream.write(element.toByteArray());
		} catch (IOException e) {
			throw new PersistanceException();
		}
		
	}

}
