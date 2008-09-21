package api.bo.BPlusTree;

import bplus.elements.BPlusLeafElement;
import bplus.exceptions.KeyNotFoundException;
import bplus.keys.BPlusElementKey;

// EL BO encapsula la logica de interaccion con nodos, index set, secuencial set, etc...
// por lo tanto solo provee metodo para insertar ,eliminar, actualizar y recuperar elementos de hojas

public interface BPlusNodeBo {
	/*public abstract void updateNode(BPlusNode node) throws DataAccessException;
	public abstract BPlusNodeKey insertNode(BPlusNode node) throws DataAccessException;
	public abstract BPlusNode getNode(BPlusNodeKey id) throws DataAccessException;*/

	public void insertElement( BPlusLeafElement element ) ;
	public void removeElement( BPlusElementKey elementKey ) throws KeyNotFoundException ;
	public void updateElement( BPlusLeafElement element ) throws KeyNotFoundException ;
	public BPlusLeafElement getElement( BPlusElementKey elementKey) throws KeyNotFoundException ; 
}
