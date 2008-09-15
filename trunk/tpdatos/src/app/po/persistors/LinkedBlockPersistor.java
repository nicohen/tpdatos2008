package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import dto.LinkedBlock;
import exceptions.PersistanceException;

public class LinkedBlockPersistor extends AbstractPersistor<LinkedBlock<Integer>> {

	public LinkedBlockPersistor(int maxSize) {
		super(maxSize);
	}

	
	
	
	@Override
	public LinkedBlock<Integer> read(DataInputStream stream) throws PersistanceException {
		// TODO Auto-generated method stub
		int i=0;
		LinkedBlock<Integer> reg=new LinkedBlock<Integer>();
		try{
			while (i<this.maxSize){
			reg.setDoc(stream.readInt());
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
		
	}




}
