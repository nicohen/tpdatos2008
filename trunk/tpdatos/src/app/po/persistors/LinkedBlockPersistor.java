package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import dto.LinkedBlock;
import exceptions.PersistanceException;

public class LinkedBlockPersistor extends AbstractPersistor<LinkedBlock> {

	public LinkedBlockPersistor(int maxSize) {
		super(maxSize);
	}

	
	
	@Override
	public void write(LinkedBlock element, DataOutputStream stream)
			throws PersistanceException {
		// TODO Auto-generated method stub
		
	}

	@Override
	public LinkedBlock read(DataInputStream stream) throws PersistanceException {
		// TODO Auto-generated method stub
		int i=0;
		LinkedBlock reg=new LinkedBlock();
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
}
