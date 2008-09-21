package api.bo.BPlusTree;

import bplus.elements.BPlusLeafElement;
import bplus.exceptions.KeyNotFoundException;
import bplus.keys.BPlusElementKey;
import exceptions.DataAccessException;

// EL BO encapsula la logica de interaccion con nodos, index set, secuencial set, etc...
// por lo tanto solo provee metodo para insertar ,eliminar, actualizar y recuperar elementos de hojas

public interface BPlusTreeBo {
	public void insertElement( BPlusLeafElement element ) throws DataAccessException ;
	//public void removeElement( BPlusElementKey elementKey ) throws KeyNotFoundException ;
	//public void updateElement( BPlusLeafElement element ) throws KeyNotFoundException ;
	public BPlusLeafElement getElement( BPlusElementKey elementKey) throws KeyNotFoundException, DataAccessException ; 
}
