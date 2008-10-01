package app.po.files;

import exceptions.DataAccessException;


public class StreamFile<E> {
	
	private E separator;
	
	public StreamFile( E separator ) {
		this.separator = separator;
	}
	
	// devuelve la direccion a donde agrego la secuencia
	// de registros, persistidos uno tras otro
	public int add( E[] vect )  throws DataAccessException {
		// TODO
		return 0;
	}
	
	public E[] get(int direccion) throws DataAccessException {

		return null;
	}


}
