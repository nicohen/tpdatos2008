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
		try {
			int size = stream.readInt();
			byte[] arry_ = new byte[dataSize-4];
			stream.read(arry_);

			byte[] arry = new byte[size];
			for (int i=0;i<size;i++){
				arry[i]=arry_[i];
			}
			
			return new GammaDistancesBlock(dataSize-4,arry);
		} catch (IOException e) {
			throw new PersistanceException("i/o error",e);
		}
 
	}

	public void write(GammaDistancesBlock element, DataOutputStream stream) throws PersistanceException {
		try {
			// completar con ceros e insertar la longitud
			byte[] arry = new byte[dataSize-4];

			// rellenar con ceros el array
			byte[] byteArray = element.toByteArray();
			ByteArrayInputStream inputStream = 
				new ByteArrayInputStream( byteArray );
			inputStream.read(arry);
			
			stream.writeInt(byteArray.length);
			stream.write(arry);
			
		} catch (IOException e) {
			throw new PersistanceException();
		}
		
	}

}
