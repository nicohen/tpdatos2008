package api.query.tree;

import java.util.Iterator;

public interface Query {
	
	// el metodo execute, simplemente devuelve en un iterator
	// el iterador de los resultados de la query (ids de documentos)
	public Iterator<Integer> execute();
}
