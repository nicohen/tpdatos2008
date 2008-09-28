package api;


import api.po.persistors.Persistor;
import dto.LinkedBlock;
import exceptions.DataAccessException;

public class VariableLinkedBlocksManager extends LinkedBlocksManager<byte[]> {

	public VariableLinkedBlocksManager(String path,
			Persistor<LinkedBlock<byte[]>> persistor) throws DataAccessException {
		super(path, 0, persistor);
		// TODO Auto-generated constructor stub
	}
	
	public void add(byte[] elem,int blockId){
		
		LinkedBlock<byte[]> reg=new LinkedBlock<byte[]>();
		LinkedBlock<byte[]> regAux=new LinkedBlock<byte[]>();
		int newBlockId=0,nextBlockId=0,dataSize=0;
		try {
			dataSize=elem.length+LinkedBlock.REG_ADMIN_DATA;//el 2 es el nro de long a leer
			reg=archivo.get(blockId);
			
			while(reg.getNextBlock()!=0){
				if (dataSize<=reg.getFreeRegsNum())
					break;
				nextBlockId=reg.getNextBlock();
				reg=archivo.get(reg.getNextBlock());
			}
			
			//si no hay puntero a siguiente pero el bloque esta lleno
			if (dataSize>reg.getFreeRegsNum()){
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
		}
		
	}

}
