package linkedblocks.codification;

import java.io.ByteArrayOutputStream;
import java.io.IOException;

import linkedblocks.utils.KeyCodificationUtils;
import api.po.persistors.DistancesBlock;
import exceptions.PersistanceException;

public class GammaDistancesBlock implements DistancesBlock {

//	private byte[] byteArray;
	private int maxSize;
	private ByteArrayOutputStream stream;
	
	// el modificador de acceso del constructor es package
	// para que solo las clases de este paquete puedan
	// instanciarla
	
	GammaDistancesBlock( int maxsize ) {
		this.maxSize = maxsize;
	}
	
	public int[] decodeDistances() {
		// TODO Auto-generated method stub
		return null;
	}

	public void encodeDistance(int distance) throws PersistanceException {
		byte[] gamma1 = KeyCodificationUtils.gammaEncode(distance);
		
		if (stream.toByteArray().length + gamma1.length > this.maxSize ) {
			throw new PersistanceException("Encode Overflow");
		}
		
		// concatenar el nuevo byte array al q tenemos ahora
		try {
			stream.write(gamma1);
		} catch (IOException e) {
			// NOTE: esto no va a pasar
			throw new PersistanceException();
		}
	}

	public byte[] toByteArray() {
		return stream.toByteArray();
	}

}
