package api;
import java.util.ArrayList;
import java.util.Iterator;

import exceptions.DataAccessException;
import files.SecuencialFile;
import persistors.LinkedBlockPersistor;
import registros.LinkedBlock;
public class LinkedBlocksManager {

	int blockSize;
	SecuencialFile<LinkedBlock> archivo;
	
	public LinkedBlocksManager(String path,int size) throws DataAccessException{
		LinkedBlockPersistor persistor=new LinkedBlockPersistor(1); 
		archivo=new SecuencialFile<LinkedBlock>(path, persistor );
		blockSize=size;
	}

	public ArrayList<Integer> get(int blockId){
		
		LinkedBlock reg=new LinkedBlock();
		Iterator<Integer> it;
		ArrayList<Integer> listaRet=new ArrayList<Integer>();
		try {
			reg=archivo.get(blockId);
			it=reg.getListaDocs().iterator();
			while(it.hasNext()){
				listaRet.add(it.next());
			}
			while (reg.getNextBlock()!=0){
				it=reg.getListaDocs().iterator();
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
	
	public void add(int idDoc,int blockId){
		
		LinkedBlock reg=new LinkedBlock();
		try {
			reg=archivo.get(blockId);
			while(reg.getNextBlock()!=0){
				reg=archivo.get(reg.getNextBlock());
			}
			//si no hay puntero a siguiente pero el bloque esta lleno
			if (reg.getListaDocs().size()==blockSize){
			//TODO completar nextBlock, y agregar nuevo bloque con idDoc al final del archivo
			}
			
			else{//hay lugar en el bloque
			//TODO cargar la listaDocs de reg con el idDoc
			//TODO grabar el reg en esa posicion
			archivo.add(reg);
			}
		} catch (DataAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}