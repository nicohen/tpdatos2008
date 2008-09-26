package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.util.Iterator;

import dto.LinkedBlock;
import exceptions.PersistanceException;

public class LinkedBlockByteArrayPersistor extends AbstractPersistor<LinkedBlock<byte[]>> {

	public LinkedBlockByteArrayPersistor(int maxSize) {
		super(maxSize+8);
	}

	
	
	
	@Override
	public LinkedBlock<byte[]> read(DataInputStream stream) throws PersistanceException {
		// TODO Auto-generated method stub
		int i=0;
		char regsize;
		//Registro:
		//nextblock,freespace,cantbytes,byte[],cantbytes,byte[], y asi
		
		
		LinkedBlock<byte[]> reg=new LinkedBlock<byte[]>();
		try{
			reg.setNextBlock(stream.readInt());
			reg.setFreeRegsNum(stream.readInt()); //cantidad de bytes libres en el bloque
			while (i<this.maxSize){
				regsize=stream.readChar(); //antes de cada tira de bytes hay un char que indica bytes a leer
				i++;
				if (regsize!=0){
					byte[] aux=new byte[regsize];
					for(int j=0;j<regsize;j++){
						aux[j]=stream.readByte();
						i++;
						}
					reg.setElem(aux);
				}
			}
			
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
			stream.writeInt(element.getNextBlock());
			stream.writeInt(element.getFreeRegsNum());
			while(it.hasNext()){
				stream.writeChar(it.next().length);
				for(int j=0;j<it.next().length;j++)
				stream.writeByte(it.next()[j]);
			}
			for(i=element.getListaElem().size();i<this.maxSize/4-1;i++){
				stream.writeInt(0);
			}
			
		}
		catch (IOException e){
			throw new PersistanceException("Error persistiendo Elemento.",e);
		}
		
	}




}
