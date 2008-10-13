package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import api.po.persistors.Persistor;
import dto.LinkedBlockB;
import exceptions.PersistanceException;


public class LinkedBlockPersistor<E> extends MaxSizeAbstractPersistor<LinkedBlockB<E> >{

	private Persistor<E> subPersistor;
	private final static int INFORMACION_CONTROL = 4;
	
	public LinkedBlockPersistor( Persistor<E> subPersistor) {
		super( subPersistor.getDataSize() + INFORMACION_CONTROL);
		this.subPersistor = subPersistor;
	}

	public LinkedBlockB<E> read(DataInputStream stream) throws PersistanceException {
		// TODO Auto-generated method stub
		
		LinkedBlockB<E> linkedBlock = new LinkedBlockB<E>();
		E aux = subPersistor.read(stream);

		linkedBlock.setElem(aux);
		
		int blockId;
		try {
			blockId = stream.readInt();
		} catch (IOException e) {
			throw new PersistanceException();
		}
		linkedBlock.setNextBlock(blockId);
		
		return linkedBlock;
		
	}

	public void write(LinkedBlockB<E> element, DataOutputStream stream) throws PersistanceException {
		subPersistor.write(element.getElem(), stream);
		try {
			stream.writeInt(element.getNextBlock());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			throw new PersistanceException();
		}
		
	}

}
