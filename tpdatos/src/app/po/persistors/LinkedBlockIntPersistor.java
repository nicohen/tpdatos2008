package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.util.Iterator;

import dto.LinkedBlock;
import exceptions.PersistanceException;

public class LinkedBlockIntPersistor extends AbstractPersistor<LinkedBlock<Integer>> {

	public LinkedBlockIntPersistor(int maxSize) {
		super(maxSize);
	}

	
	
	
	@Override
	public LinkedBlock<Integer> read(DataInputStream stream) throws PersistanceException {
		// TODO Auto-generated method stub
		int i=0;
		int aux;
		LinkedBlock<Integer> reg=new LinkedBlock<Integer>();
		try{
			while (i<this.maxSize/4 -1){
			aux=stream.readInt();
			if (aux!=0)
			reg.setElem(aux);
			i++;
			}
			reg.setNextBlock(stream.readInt());
		}
			catch (IOException e) {
				// TODO Auto-generated catch block
				throw new PersistanceException("Error Recuperando Elemento.",e);
			}
		
		return reg;
	}



	@Override
	public void write(LinkedBlock<Integer> element, DataOutputStream stream)
			throws PersistanceException {
		// TODO Auto-generated method stub
		int i;
		Iterator<Integer> it;
		it=element.getListaElem().iterator();
		try{
			while(it.hasNext()){
				stream.writeInt(it.next());
			}
			for(i=element.getListaElem().size();i<this.maxSize/4-1;i++){
				stream.writeInt(0);
			}
			stream.writeInt(element.getNextBlock());
		}
		catch (IOException e){
			throw new PersistanceException("Error persistiendo Elemento.",e);
		}
		
	}




}
