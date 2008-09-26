package app.dao.bplus;

import java.util.HashMap;
import java.util.Map;

import api.dao.BPlusTree.BPlusNodeDao;
import bplus.keys.BPlusNodeKey;
import bplus.nodes.BPlusNode;
import exceptions.DataAccessException;

public class BPlusNodeDaoTest implements BPlusNodeDao {

	
	private Map<Integer, BPlusNode> map = new HashMap<Integer,BPlusNode>();
	private BPlusNodeKey nextKey;
	private Integer rootNode;
	
	public BPlusNodeDaoTest() {
		nextKey = new BPlusNodeKey(0);
	}
	
	@Override
	public BPlusNode getNode(BPlusNodeKey id) throws DataAccessException {
		// TODO Auto-generated method stub
		BPlusNode node = map.get(id.getValue());
		
		// FIXME: agregarle una causa a la excepcion
		
		if (node == null) throw new DataAccessException();
		return node;
	}

	@Override
	public BPlusNodeKey insertNode(BPlusNode node) throws DataAccessException {
		// TODO Auto-generated method stub
		
		BPlusNodeKey auxNextKey = new BPlusNodeKey( nextKey.getValue() );
		
		map.put(nextKey.getValue(), node);
		node.setNodeKey(auxNextKey);
		// incrementar el nextKey
		nextKey.setValue(nextKey.getValue()+1);
		return auxNextKey;
	}

	@Override
	public void updateNode(BPlusNode node) throws DataAccessException {
		// TODO Auto-generated method stub
		map.put(node.getNodeKey().getValue(), node);
	}

	@Override
	public int getSize() {
		return this.map.size();
	}

	@Override
	public BPlusNode getRootNode(BPlusNodeKey plusNodeKey)
			throws DataAccessException {
		// TODO IMPLEMENTAR!!!
		
		return getNode( plusNodeKey );
	}

	@Override
	public void setRootNode(BPlusNodeKey plusNodeKey) {
		this.rootNode= plusNodeKey.getValue();
	}

}
