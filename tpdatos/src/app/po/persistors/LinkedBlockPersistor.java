package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import api.po.persistors.Persistor;

import dto.LinkedBlock;
import exceptions.PersistanceException;


public class LinkedBlockPersistor<E> extends MaxSizeAbstractPersistor<LinkedBlock<E> >{

	private Persistor<E> subPersistor;
	private final static int INFORMACION_CONTROL = 8;
	
	public LinkedBlockPersistor( Persistor<E> subPersistor) {
		super( subPersistor.getDataSize() + INFORMACION_CONTROL);
		this.subPersistor = subPersistor;
	}

	public LinkedBlock<E> read(DataInputStream stream) throws PersistanceException {
		// TODO Auto-generated method stub
		
		LinkedBlock<E> linkedBlock = new LinkedBlock<E>();
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

	public void write(LinkedBlock<E> element, DataOutputStream stream) throws PersistanceException {
		// TODO
		
	}

}
