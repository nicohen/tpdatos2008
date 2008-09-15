package api;
import java.util.ArrayList;
import java.util.Iterator;

import dto.LinkedBlock;

import api.po.persistors.Persistor;
import app.po.files.RelativeFile;

import exceptions.DataAccessException;
public class LinkedBlocksManager<E> {

	int blockSize;
	RelativeFile<LinkedBlock<E>> archivo;
	
	public LinkedBlocksManager(String path,int size) throws DataAccessException{
		//LinkedBlockPersistor persistor=new LinkedBlockPersistor(blockSize);
		Persistor<LinkedBlock<E>> persistor = null;
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
				it=reg.getListaElem().iterator();
				while(it.hasNext()){
					listaRet.add(it.next());
				}
				reg=archivo.get(reg.getNextBlock());
			}
			
			
		} catch (DataAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return listaRet;
	}
	
	public void add(E elem,int blockId){
		
		LinkedBlock<E> reg=new LinkedBlock<E>();
		LinkedBlock<E> regAux=new LinkedBlock<E>();
		int newBlockId;
		try {
			reg=archivo.get(blockId);
			while(reg.getNextBlock()!=0){
				reg=archivo.get(reg.getNextBlock());
			}
			//si no hay puntero a siguiente pero el bloque esta lleno
			if (reg.getListaElem().size()==blockSize){
				regAux.setDoc(elem);
				newBlockId=archivo.add(regAux);//obtengo id del siguiente bloque
				reg.setNextBlock(newBlockId);//seteo el puntero a siguiente
				archivo.update(reg.getCurrentBlock(), reg);//actualizo
			}
			
			else{//hay lugar en el bloque
			reg.setDoc(elem);
			archivo.update(reg.getCurrentBlock(),reg);
			}
		} catch (DataAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}