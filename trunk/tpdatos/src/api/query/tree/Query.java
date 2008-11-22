package api.query.tree;

import java.util.Iterator;
import java.util.List;

public interface Query {
	
	// el metodo getIterator, simplemente devuelve en un iterator
	// para leer los resultados de la query de manera secuencial
	public Iterator<Integer> iterator();
	
	// metodo para debugging, hace un dump de la query en forma de tree
	public void dump(int ntabs);
}
