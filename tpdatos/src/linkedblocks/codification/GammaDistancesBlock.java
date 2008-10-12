package linkedblocks.codification;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

import linkedblocks.utils.KeyCodificationUtils;
import api.po.persistors.DistancesBlock;
import exceptions.PersistanceException;

public class GammaDistancesBlock implements DistancesBlock {

//	private byte[] byteArray;
	private int maxSize;
	private ByteArrayOutputStream stream = new ByteArrayOutputStream();
	
	// el modificador de acceso del constructor es package
	// para que solo las clases de este paquete puedan
	// instanciarla
	
	public GammaDistancesBlock( int maxsize ) {
		this.maxSize = maxsize;
	}
	
	public Iterator<Integer> decodeDistances() {
		List<Integer> lista = new LinkedList<Integer>();
		
		byte[] arry = this.toByteArray();
		
		int k = 0;
		while ( k < arry.length*8) {
			Integer distance = KeyCodificationUtils.gammaDecode(arry, k);
			int nextByteOffset = KeyCodificationUtils.gammaDecodeLength(arry, k);
			nextByteOffset = ((nextByteOffset + 8) / 8) * 8;
			lista.add(distance);
			k += nextByteOffset;
		}
		
		return lista.iterator();
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
