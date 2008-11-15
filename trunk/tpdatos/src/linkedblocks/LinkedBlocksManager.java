package linkedblocks;

import java.util.ArrayList;
import java.util.Iterator;

import api.po.files.File;
import api.po.persistors.Persistor;
import app.po.files.RelativeFile;
import dto.LinkedBlock;
import exceptions.DataAccessException;
import exceptions.PersistanceException;

public class LinkedBlocksManager<E> {

	private File<LinkedBlock<E>> archivo;
	
	
	public LinkedBlocksManager(String path,Persistor<LinkedBlock<E>> persistor) throws DataAccessException{
		try {
			archivo=new RelativeFile<LinkedBlock<E>>(path, persistor );
		} catch (PersistanceException e) {
			throw new DataAccessException("Error inicializando LinkedBlocksManager.",e);
		}
	}
	
	// obtiene toda la lista de linked blocks
	public Iterator<E> get(int blockId) throws DataAccessException{
		
		LinkedBlock<E> reg;
		//Iterator<E> it;
	
		ArrayList<E> listaRet=new ArrayList<E>();
		reg=archivo.get(blockId);
		listaRet.add(reg.getElem());

		while (reg.getNextBlock()!=0){
			reg=archivo.get(reg.getNextBlock());
			listaRet.add(reg.getElem());
		}
		return listaRet.iterator();
	}
	
	public int add( E element ) throws PersistanceException {
		LinkedBlock<E> regAux;
		regAux = new LinkedBlock<E>();
		regAux.setElem(element);
		try {
			return archivo.add(regAux);
		} catch (DataAccessException e) {
			throw new PersistanceException( "",e);
		}
	}
	
	// updatea el ultimo de la cadena partiendo de blockId
	
	public void updateLast( E element, int blockId) throws PersistanceException {
		LinkedBlock<E> reg;
		try {
			
			// no se puede hacer un update directamente al archivo
			// ya que solo hay que modificar el elemento en ese bloque
			
			int lastBlockId=blockId;
		
			reg=archivo.get(blockId);
			while(reg.getNextBlock()!=0){
				lastBlockId=reg.getNextBlock();
				reg=archivo.get(lastBlockId);
			}

			reg.setElem(element);
			archivo.update(lastBlockId, reg);
			
		} catch (DataAccessException e) {
			throw new PersistanceException();
		}
	}
	
	public void add( E element, int blockId) throws PersistanceException{
		
		LinkedBlock<E> reg;
		LinkedBlock<E> regAux;
		int newBlockId=0,nextBlockId=0;
		try {
			reg=archivo.get(blockId);
			while(reg.getNextBlock()!=0){
				nextBlockId=reg.getNextBlock();
				reg=archivo.get(reg.getNextBlock());

			}
			
			regAux = new LinkedBlock<E>();
			regAux.setElem(element);
			newBlockId=archivo.add(regAux);//obtengo id del siguiente bloque
			reg.setNextBlock(newBlockId);//seteo el puntero a siguiente
			
			if (nextBlockId!=0) {
				   archivo.update(nextBlockId,reg);
			} else {
				   archivo.update(blockId, reg);
			}
			
			
		} catch (DataAccessException e) {
			throw new PersistanceException("",e);
		}
		
	}

}
