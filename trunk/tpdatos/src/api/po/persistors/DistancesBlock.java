package api.po.persistors;

import java.util.Iterator;

import exceptions.PersistanceException;

public interface DistancesBlock {
	// agrega una distancia al bloque
	// puede tirar PersistanceExcepcion dado que
	// no haya lugar para insertar esa distancia
	
	public void encodeDistance( int distance ) throws PersistanceException;
	
	
	// obtiene un array de bytes del bloque
	public byte[] toByteArray(); 
	

	// obtiene las distancias decodificadas
	public Iterator<Integer> decodeDistances();

}
