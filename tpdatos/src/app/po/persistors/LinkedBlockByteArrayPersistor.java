package app.po.persistors;


import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import dto.LinkedBlock;
import exceptions.PersistanceException;

public class LinkedBlockByteArrayPersistor extends MaxSizeAbstractPersistor<LinkedBlock<byte[]>> {

	public LinkedBlockByteArrayPersistor(int maxSize) {
		super(maxSize+LinkedBlock.BLOCK_ADMIN_DATA);
	}

	
	
	
	@Override
	public LinkedBlock<byte[]> read(DataInputStream stream) throws PersistanceException {
		// TODO Auto-generated method stub
		int i=0;
		short regsize=0;
		//Registro:
		//nextblock,freespace,cantbytes,byte[],cantbytes,byte[], y asi
		
		
		LinkedBlock<byte[]> reg=new LinkedBlock<byte[]>();
		try{
			reg.setNextBlock(stream.readInt());
			reg.setFreeRegsNum(stream.readInt()); //cantidad de bytes libres en el bloque
			i+=LinkedBlock.BLOCK_ADMIN_DATA;
			while (i<this.maxSize){
				regsize=stream.readShort(); //antes de cada tira de bytes hay un char que indica bytes a leer
				if ((regsize<=0)&&(i==8)) //el bloque esta vacio, esto es para evitar un flag de vacio
				{
					reg.setFreeRegsNum(this.maxSize-LinkedBlock.BLOCK_ADMIN_DATA);
					return reg;
				}
					i+=LinkedBlock.REG_ADMIN_DATA;
				if (regsize>0){
					byte[] aux=new byte[regsize];
					for(int j=0;j<regsize;j++){
						aux[j]=stream.readByte();
						i++;
						}
					reg.setElem(aux);
				}
				else
				return reg;
			}
			reg.setFreeRegsNum(0);//si salio del while es porque no hay mas lugar
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
		int dataSize=getDataSize(element);
		element.setFreeRegsNum(maxSize-LinkedBlock.BLOCK_ADMIN_DATA);
		try{
			stream.writeInt(element.getNextBlock());
			stream.writeInt(element.getFreeRegsNum()-dataSize);
			for(int j=0;j<element.getListaElem().size();j++)
			{
				stream.writeShort(element.getListaElem().get(j).length);
				for(int k=0;k<element.getListaElem().get(j).length;k++)
				{
					stream.writeByte(element.getListaElem().get(j)[k]);
				}
			}
			for(int l=0;l<element.getFreeRegsNum()-dataSize;l++){
				stream.writeByte(0);
			}
			
		}
		catch (IOException e){
			throw new PersistanceException("Error persistiendo Elemento.",e);
		}
		
	}

	//devuelve cantidad de bytes que ocupa el registro
	//tuve que hacer esto para poder meter el dato administrativo al principio del bloque
	private int getDataSize(LinkedBlock<byte[]> element){
		int i=0;
		for(int j=0;j<element.getListaElem().size();j++)
		{
			//stream.writeShort(element.getListaElem().size());
			i+=LinkedBlock.REG_ADMIN_DATA;
			for(int k=0;k<element.getListaElem().get(j).length;k++)
			{
				i++;
			}
		}
	return i;
	}

}
