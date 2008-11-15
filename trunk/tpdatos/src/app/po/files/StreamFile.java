package app.po.files;

import java.util.LinkedList;

import api.po.persistors.Persistor;
import exceptions.DataAccessException;
import exceptions.PersistanceException;


public class StreamFile {
	
	private RelativeFile<Byte> relativo;
	private Byte separator;
	
	public StreamFile( String path, Persistor<Byte> persistor , Byte separator ) throws DataAccessException {
		this.separator = separator;
		try {
			relativo = new RelativeFile<Byte>(path,persistor);
		} catch (PersistanceException e) {
			throw new DataAccessException("",e);
		}
	}
	
	// devuelve la direccion a donde agrego la secuencia
	// de registros, persistidos uno tras otro
	public int add( byte[] vect )  throws DataAccessException {
		boolean primero = true;
		int direccion = 0;

		try {

			if (vect.length == 0) {
				throw new DataAccessException();
			}
			for ( Byte e : vect ) {
				if (primero ) {
					direccion = relativo.add(e);
					primero = false;
				}
			
				relativo.add(e);
			}
			
			relativo.add(this.separator);

		} catch (PersistanceException e1) {
			throw new DataAccessException();
		}
		
		return direccion;

	}
	
	public byte[] get(int direccion) throws DataAccessException {

		// esta longitud maxima es un tema algoritmico
		// NO de organizacion, es para saber cuantas
		// posiciones alocar en el array
		LinkedList<Byte> list = new LinkedList<Byte>();
		
		while (true) {
			Byte aux = relativo.get(direccion);
			if (aux.equals(this.separator)) break;
			
			list.add(aux);
			
			direccion++;
		}
		
		byte[] retorno = new byte[list.size()];
		
		int i = 0;
		for (Byte aux : list) {
			retorno[i] = aux.byteValue();
			i++;
		}
		return retorno;
	}


}
