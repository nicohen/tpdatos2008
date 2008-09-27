package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import api.po.persistors.Persistor;
import bplus.elements.BPlusElement;
import bplus.elements.BPlusIndexElement;
import bplus.elements.BPlusLeafElement;
import bplus.keys.BPlusElementKey;
import bplus.keys.BPlusNodeKey;
import exceptions.PersistanceException;

public class BPlusElementPersistor implements Persistor<BPlusElement> {

	private byte LEAF_TYPE= 0;
	private byte INDEX_TYPE= 1;
	private Persistor<Integer> intePersistor= new IntegerPersistor();
	private SimpleStringPersistor stringPersistor= new SimpleStringPersistor();
	
	@Override
	public int getDataSize() {
		return 0;
	}

	@Override
	public BPlusElement read(DataInputStream stream)
			throws PersistanceException {
		try {
			byte type= stream.readByte();
			if (type==LEAF_TYPE){
				return readLeafElement(stream);
			}else{
				return readIndexElement(stream);
			}
		} catch (IOException e) {
			throw new PersistanceException("Error recuperando elemento.",e);
		}
	}

	private BPlusElement readIndexElement(DataInputStream stream) throws PersistanceException {
		BPlusElementKey key= new BPlusElementKey(stringPersistor.read(stream));
		BPlusIndexElement element= new BPlusIndexElement(key);
		BPlusNodeKey nodeKey= new BPlusNodeKey();
		nodeKey.setValue(this.intePersistor.read(stream));
		element.setRelatedNode(nodeKey);
		return element;
	}

	private BPlusElement readLeafElement(DataInputStream stream) throws PersistanceException {
		BPlusElementKey key= new BPlusElementKey(stringPersistor.read(stream));
		BPlusLeafElement element= new BPlusLeafElement(key);
		element.setValue(this.intePersistor.read(stream));
		return element;
	}

	@Override
	public void write(BPlusElement element, DataOutputStream stream)
			throws PersistanceException {
		try {
			if (element instanceof BPlusLeafElement) {
				stream.writeByte(LEAF_TYPE);
				writeLeafElement((BPlusLeafElement)element,stream);
			}else{
				stream.writeByte(INDEX_TYPE);
				writeIndexElement((BPlusIndexElement)element,stream);
			}
		} catch (IOException e) {
			throw new PersistanceException("Error persistiendo elemento: "+element,e);
		}
	}
	
	private void writeLeafElement(BPlusLeafElement element, DataOutputStream stream) throws PersistanceException {
		stringPersistor.write(element.getKey().getValue(), stream);
		intePersistor.write(element.getValue(), stream);
	}
	
	private void writeIndexElement(BPlusIndexElement element, DataOutputStream stream) throws PersistanceException {
		stringPersistor.write(element.getKey().getValue(), stream);
		intePersistor.write(element.getRelatedNode().getValue(), stream);
	}
	

	@Override
	public int getElementSize(BPlusElement element) {
		if (element instanceof BPlusLeafElement) {
			return getLeafElementSize((BPlusLeafElement)element) + 1;
		}else{
			return getIndexElementSize((BPlusIndexElement)element) + 1;
		}
	}

	private int getIndexElementSize(BPlusIndexElement element) {	
		return stringPersistor.getElementSize(element.getKey().getValue()) +
				intePersistor.getElementSize(element.getRelatedNode().getValue());
	}

	private int getLeafElementSize(BPlusLeafElement element) {
		return stringPersistor.getElementSize(element.getKey().getValue()) +
		intePersistor.getElementSize(element.getValue());	
	}
}
