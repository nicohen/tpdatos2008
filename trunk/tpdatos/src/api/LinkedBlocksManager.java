package api;
import java.util.ArrayList;
import java.util.Iterator;

import api.po.files.File;
import api.po.persistors.Persistor;
import app.po.files.RelativeFile;
import dto.LinkedBlock;
import exceptions.DataAccessException;
import exceptions.PersistanceException;
public class LinkedBlocksManager<E> {

	int blockSize;
	File<LinkedBlock<E>> archivo;
	
	public LinkedBlocksManager(String path,int size,Persistor<LinkedBlock<E>> persistor) throws DataAccessException{
		archivo=new RelativeFile<LinkedBlock<E>>(path, persistor );
		blockSize=size;
	}

	public ArrayList<E> get(int blockId){
		
		LinkedBlock<E> reg=new LinkedBlock<E>();
		Iterator<E> it;
	
		ArrayList<E> listaRet=new ArrayList<E>();
		try {
			reg=archivo.get(blockId);
			it=reg.getListaElem().iterator();
			while(it.hasNext()){
				listaRet.add(it.next());
			}
			while (reg.getNextBlock()!=0){
				reg=archivo.get(reg.getNextBlock());
				it=reg.getListaElem().iterator();
				while(it.hasNext()){
					listaRet.add(it.next());
				}
			}
			
			
		} catch (DataAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return listaRet;
	}
	public Integer addBlock(){
		LinkedBlock<E> reg=new LinkedBlock<E>();
		Integer newBlockId=0;
		try {
			newBlockId=archivo.add(reg);
		} catch (DataAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (PersistanceException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return newBlockId;
	}
	public void add(E elem,int blockId){
		
		LinkedBlock<E> reg=new LinkedBlock<E>();
		LinkedBlock<E> regAux=new LinkedBlock<E>();
		int newBlockId=0,nextBlockId=0;
		try {
			reg=archivo.get(blockId);	
			while(reg.getNextBlock()!=0){
				nextBlockId=reg.getNextBlock();
				reg=archivo.get(reg.getNextBlock());
			}
			//si no hay puntero a siguiente pero el bloque esta lleno
			if (reg.getListaElem().size()==blockSize){
				regAux.setElem(elem);
				newBlockId=archivo.add(regAux);//obtengo id del siguiente bloque
				reg.setNextBlock(newBlockId-1);//seteo el puntero a siguiente
				if (nextBlockId!=0)
				   archivo.update(nextBlockId,reg);
				else
				   archivo.update(blockId, reg);
			}
			
			else{//hay lugar en el bloque
			reg.setElem(elem);
			if (nextBlockId!=0)
			archivo.update(nextBlockId,reg);
			else
			archivo.update(blockId, reg);
			}
		} catch (DataAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (PersistanceException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}