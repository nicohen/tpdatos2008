package api.query.tree;

import java.util.Iterator;
import java.util.List;

public interface Query {
	
	// el metodo execute, simplemente devuelve en un iterator
	// el iterador de los resultados de la query (ids de documentos)
	public Iterator<Integer> execute();
	
	// ejecuta la query , pero esta vez devolviendo una lista
	public List<Integer> executeGetList();
}
