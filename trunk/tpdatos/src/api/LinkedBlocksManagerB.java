package api;

import java.util.ArrayList;

import api.po.files.File;
import api.po.persistors.DistancesBlock;
import api.po.persistors.Persistor;
import app.po.files.RelativeFile;
import dto.LinkedBlock;
import dto.LinkedBlockB;
import exceptions.DataAccessException;
import exceptions.PersistanceException;

public class LinkedBlocksManagerB<E extends DistancesBlock> {

	File<LinkedBlockB<E>> archivo;
	
	public LinkedBlocksManagerB(String path,Persistor<LinkedBlockB<E>> persistor) throws DataAccessException{
		archivo=new RelativeFile<LinkedBlockB<E>>(path, persistor );
//		blockSize=size;
	}
	
	private E createElement() {
		//TODO : desharcodear, usar algun Factory 
		return (E) new GammaDistancesBlock(512);
	}

	public ArrayList<Integer> get(int blockId){
		
		LinkedBlockB<E> reg;
		//Iterator<E> it;
	
		ArrayList<Integer> listaRet=new ArrayList<Integer>();
		try {
			reg=archivo.get(blockId);

			int[] distances;
			
			distances = reg.getElem().decodeDistances();
			for (int dist : distances ) {
				listaRet.add(new Integer(dist) );
			}
			
			while (reg.getNextBlock()!=0){
				distances = reg.getElem().decodeDistances();
				for (int dist : distances ) {
					listaRet.add(new Integer(dist) );
				}
			}
			
			
		} catch (DataAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return listaRet;
	}
	
	public void add(int distance,int blockId){
		
		LinkedBlockB<E> reg;
		LinkedBlockB<E> regAux;
		int newBlockId=0,nextBlockId=0;
		try {
			reg=archivo.get(blockId);
			while(reg.getNextBlock()!=0){
				nextBlockId=reg.getNextBlock();
				reg=archivo.get(reg.getNextBlock());
			}
			
			
			try {
				reg.getElem().encodeDistance(distance);
				// si no tira excepcion, updatear el elemento
				if (nextBlockId!=0)
					archivo.update(nextBlockId,reg);
					else
					archivo.update(blockId, reg);
				
			} catch ( PersistanceException e ) {
				
				// el registro esta lleno
				E elem = createElement();
				
				regAux = new LinkedBlockB<E>();
				regAux.setElem(elem);
				newBlockId=archivo.add(regAux);//obtengo id del siguiente bloque
				reg.setNextBlock(newBlockId-1);//seteo el puntero a siguiente
				if (nextBlockId!=0)
				   archivo.update(nextBlockId,reg);
				else
				   archivo.update(blockId, reg);				
			}
			
		} catch (DataAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
