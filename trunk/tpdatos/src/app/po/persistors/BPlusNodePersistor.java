package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.util.Iterator;

import api.po.persistors.Persistor;
import bplus.elements.BPlusElement;
import bplus.elements.BPlusIndexElement;
import bplus.keys.BPlusNodeKey;
import bplus.nodes.BPlusIndexNode;
import bplus.nodes.BPlusLeafNode;
import bplus.nodes.BPlusNode;
import exceptions.PersistanceException;

public class BPlusNodePersistor extends AbstractPersistor<BPlusNode> {
	
	private byte LEAF_TYPE= 0;
	private byte INDEX_TYPE= 1;
	private Persistor<BPlusElement> elementPersistor= new BPlusElementPersistor();
	private Persistor<Integer> intePersistor= new IntegerPersistor();
	private int nodeSize;
	
	public BPlusNodePersistor(int nodeSize) {
		this.nodeSize=nodeSize;
	}

	@Override
	public int getDataSize() {
		// TODO Auto-generated method stub
		return nodeSize;
	}

	@Override
	public BPlusNode read(DataInputStream stream) throws PersistanceException {
		try {
			byte type= stream.readByte();
			if (type==LEAF_TYPE){
				return readLeafNode(stream);
			}else{
				return readIndexNode(stream);
			}
		} catch (IOException e) {
			throw new PersistanceException("Error recuperando elemento.",e);
		}
	}

	private BPlusNode readIndexNode(DataInputStream stream) throws PersistanceException {
		try {
			BPlusIndexNode indexNode= new BPlusIndexNode();
			indexNode.setLeftChild((BPlusIndexElement) elementPersistor.read(stream));
			byte length= stream.readByte();
			for (int i=0; i<length ;i++){
				indexNode.insertElement(elementPersistor.read(stream));
			}
			return indexNode;
		} catch (IOException e) {
			throw new PersistanceException("Error recuperando elemento.",e);
		}
	}

	private BPlusNode readLeafNode(DataInputStream stream) throws PersistanceException{
		try {
			BPlusLeafNode leafNode= new BPlusLeafNode();
			BPlusNodeKey nodeKey= new BPlusNodeKey(intePersistor.read(stream));
			leafNode.setNextNodeKey(nodeKey);
			byte length= stream.readByte();
			for (int i=0; i<length ;i++){
				leafNode.insertElement(elementPersistor.read(stream));
			}
			return leafNode;
		} catch (IOException e) {
			throw new PersistanceException("Error recuperando elemento.",e);
		}
	}

	@Override
	public void write(BPlusNode element, DataOutputStream stream)
			throws PersistanceException {
		try {
			if (element instanceof BPlusLeafNode) {
				stream.writeByte(LEAF_TYPE);
				writeLeafNode((BPlusLeafNode)element,stream);
			}else{
				stream.writeByte(INDEX_TYPE);
				writeIndexNode((BPlusIndexNode)element,stream);
			}
		} catch (IOException e) {
			throw new PersistanceException("Error persistiendo elemento: "+element,e);
		}
	}

	private void writeIndexNode(BPlusIndexNode node, DataOutputStream stream) throws PersistanceException {
		try {
			elementPersistor.write(node.getLeftChild(),stream);
			stream.writeByte(node.getElements().size());
			Iterator<BPlusElement> it= node.getElements().iterator();
			while(it.hasNext()){
				elementPersistor.write(it.next(), stream);
			}
		} catch (IOException e) {
			throw new PersistanceException("Error persistiendo elemento: "+node,e);
		}		
	}

	private void writeLeafNode(BPlusLeafNode node, DataOutputStream stream) throws PersistanceException {
		try {
			intePersistor.write(node.getNextNodeKey().getValue(),stream);
			stream.writeByte(node.getElements().size());
			Iterator<BPlusElement> it= node.getElements().iterator();
			while(it.hasNext()){
				elementPersistor.write(it.next(), stream);
			}
		} catch (IOException e) {
			throw new PersistanceException("Error persistiendo elemento: "+node,e);
		}
		
	}

//	@Override
/*	public int getElementSize(BPlusNode element) {
		return getDataSize();
	}*/

}
