package app.po.persistors;

import java.io.ByteArrayInputStream;
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
			// completar con ceros e insertar la longitud
			// TODO: insertar la longitud para poder leerlo
			byte[] arry = new byte[dataSize];
			
			ByteArrayInputStream inputStream = 
				new ByteArrayInputStream( element.toByteArray() );
			
			inputStream.read(arry);
			stream.write(arry);
			
		} catch (IOException e) {
			throw new PersistanceException();
		}
		
	}

}
