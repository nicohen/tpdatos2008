package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.util.Iterator;

import api.po.persistors.Persistor;
import api.po.persistors.SimplePersistor;
import bplus.elements.BPlusElement;
import bplus.elements.BPlusIndexElement;
import bplus.keys.BPlusNodeKey;
import bplus.nodes.BPlusIndexNode;
import bplus.nodes.BPlusLeafNode;
import bplus.nodes.BPlusNode;
import exceptions.PersistanceException;

public class BPlusNodePersistor implements Persistor<BPlusNode> {
	
	private static byte LEAF_TYPE= 0;
	private static byte INDEX_TYPE= 1;
	private SimplePersistor<BPlusElement> elementPersistor= new BPlusElementPersistor();
	private Persistor<Integer> intPersistor= new IntegerPersistor();
	private int nodeSize;
	
	public BPlusNodePersistor(int nodeSize) {
		this.nodeSize=nodeSize;
	}

	@Override
	public int getDataSize() {
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
		BPlusIndexNode indexNode= new BPlusIndexNode();
		int length= intPersistor.read(stream);
		if (length>0){
			indexNode.setLeftChild((BPlusIndexElement) elementPersistor.read(stream));
			for (int i=1; i<length ;i++){
				indexNode.insertElement(elementPersistor.read(stream));
			}
		}			
		return indexNode;
	}

	private BPlusNode readLeafNode(DataInputStream stream) throws PersistanceException{
			BPlusLeafNode leafNode= new BPlusLeafNode();
			BPlusNodeKey nodeKey= new BPlusNodeKey(intPersistor.read(stream));
			leafNode.setNextNodeKey(nodeKey);
			int length= intPersistor.read(stream);
			for (int i=0; i<length ;i++){
				leafNode.insertElement(elementPersistor.read(stream));
			}
			return leafNode;
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
		int length=node.getElements().size();
		if(node.getLeftChild()!=null){
			intPersistor.write(length+1,stream);
			elementPersistor.write(node.getLeftChild(),stream);
		}else{
			intPersistor.write(length,stream);
		}
		Iterator<BPlusElement> it= node.getElements().iterator();
		while(it.hasNext()){
			elementPersistor.write(it.next(), stream);
		}
	}

	private void writeLeafNode(BPlusLeafNode node, DataOutputStream stream) throws PersistanceException {
		if (node.getNextNodeKey()==null){
			intPersistor.write(0,stream);
		}else{
			intPersistor.write(node.getNextNodeKey().getValue(),stream);	
		}			
		intPersistor.write(node.getElements().size(),stream);
		Iterator<BPlusElement> it= node.getElements().iterator();
		while(it.hasNext()){
			elementPersistor.write(it.next(), stream);
		}		
	}

	@Override
	public int getElementSize(BPlusNode element) {
		if (element instanceof BPlusLeafNode) {
			return getLeafNodeSize((BPlusLeafNode)element)+1;
		}else{
			return getIndexNodeSize((BPlusIndexNode)element)+1;
		}
	}

	private int getIndexNodeSize(BPlusIndexNode node) {
		
		int counter= intPersistor.getDataSize();
		if(node.getLeftChild()!=null){
			counter= counter + elementPersistor.getElementSize(node.getLeftChild());
		}
		Iterator<BPlusElement> it= node.getElements().iterator();
		while(it.hasNext()){
			counter= counter + elementPersistor.getElementSize(it.next());
		}
		return counter;
	}

	private int getLeafNodeSize(BPlusLeafNode node) {
		int counter= intPersistor.getDataSize()*2;
		Iterator<BPlusElement> it= node.getElements().iterator();
		while(it.hasNext()){
			counter= counter + elementPersistor.getElementSize(it.next());
		}
		return counter;
	}
}
