package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.util.Iterator;

import dto.LinkedBlock;
import exceptions.PersistanceException;

public class LinkedBlockByteArrayPersistor extends AbstractPersistor<LinkedBlock<byte[]>> {

	public LinkedBlockByteArrayPersistor(int maxSize) {
		super(maxSize);
	}

	
	
	
	@Override
	public LinkedBlock<byte[]> read(DataInputStream stream) throws PersistanceException {
		// TODO Auto-generated method stub
		int i=0;
		//byte[] aux;
		LinkedBlock<byte[]> reg=new LinkedBlock<byte[]>();
		try{
			while (i<this.maxSize/4 -1){
			//aux=stream.readInt();
			//if (aux!=0)
			//reg.setElem(aux);
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
	public void write(LinkedBlock<byte[]> element, DataOutputStream stream)
			throws PersistanceException {
		// TODO Auto-generated method stub
		int i;
		Iterator<byte[]> it;
		it=element.getListaElem().iterator();
		try{
			while(it.hasNext()){
				for(int j=0;j<it.next().length;j++)
				stream.writeByte(it.next()[1]);
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
