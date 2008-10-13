package linkedblocks;

import java.util.ArrayList;
import java.util.Iterator;

import linkedblocks.codification.GammaDistancesBlock;

import api.po.files.File;
import api.po.persistors.DistancesBlock;
import api.po.persistors.Persistor;
import app.po.files.RelativeFile;
import dto.LinkedBlockB;
import exceptions.DataAccessException;
import exceptions.PersistanceException;

public class LinkedBlocksManagerB<E> {

	private File<LinkedBlockB<E>> archivo;
	
	
	public LinkedBlocksManagerB(String path,Persistor<LinkedBlockB<E>> persistor) throws DataAccessException{
		archivo=new RelativeFile<LinkedBlockB<E>>(path, persistor );
	}
	
	// obtiene toda la lista de linked blocks
	public Iterator<E> get(int blockId){
		
		LinkedBlockB<E> reg;
		//Iterator<E> it;
	
		ArrayList<E> listaRet=new ArrayList<E>();
		try {
			reg=archivo.get(blockId);
			listaRet.add(reg.getElem());

			while (reg.getNextBlock()!=0){
				reg=archivo.get(reg.getNextBlock());
				listaRet.add(reg.getElem());
			}

			/*Iterator<Integer> distances;
			
			distances = reg.getElem().decodeDistances();
			while (distances.hasNext() ) {
				listaRet.add(distances.next() );
			}
			*/
			
			
		} catch (DataAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return listaRet.iterator();
	}
	
	public int add( E element ) throws PersistanceException {
		LinkedBlockB<E> regAux;
		regAux = new LinkedBlockB<E>();
		regAux.setElem(element);
		try {
			return archivo.add(regAux);
		} catch (DataAccessException e) {
			// TODO Auto-generated catch block
			throw new PersistanceException( "",e);
		}
	}
	
	public void add( E element, int blockId) throws PersistanceException{
		
		LinkedBlockB<E> reg;
		LinkedBlockB<E> regAux;
		int newBlockId=0,nextBlockId=0;
		try {
			reg=archivo.get(blockId);
			while(reg.getNextBlock()!=0){
				nextBlockId=reg.getNextBlock();
				reg=archivo.get(reg.getNextBlock());

			}
			
			regAux = new LinkedBlockB<E>();
			regAux.setElem(element);
			newBlockId=archivo.add(regAux);//obtengo id del siguiente bloque
			reg.setNextBlock(newBlockId);//seteo el puntero a siguiente
			
			if (nextBlockId!=0) {
				   archivo.update(nextBlockId,reg);
			} else {
				   archivo.update(blockId, reg);
			}
			
			
		} catch (DataAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
