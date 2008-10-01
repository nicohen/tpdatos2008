package app.po.files;

import api.po.persistors.Persistor;
import exceptions.DataAccessException;
import exceptions.PersistanceException;


public class StreamFile<E> {
	
	private RelativeFile<E> relativo;
	private E separator;
	
	public StreamFile( String path, Persistor<E> persistor , E separator ) throws DataAccessException {
		this.separator = separator;
		relativo = new RelativeFile<E>(path,persistor);
	}
	
	// devuelve la direccion a donde agrego la secuencia
	// de registros, persistidos uno tras otro
	public int add( E[] vect )  throws DataAccessException {
		boolean primero = true;
		int direccion = 0;

		try {

			if (vect.length == 0) {
				throw new DataAccessException();
			}
			for ( E e : vect ) {
				if (primero ) {
					direccion = relativo.add(e);
					primero = false;
				}
			
				relativo.add(e);
			}
			
			relativo.add(this.separator);

		} catch (PersistanceException e1) {
			// TODO Auto-generated catch block
			throw new DataAccessException();
		}
		
		return direccion;

	}
	
	public E[] get(int direccion) throws DataAccessException {

		return null;
	}


}
