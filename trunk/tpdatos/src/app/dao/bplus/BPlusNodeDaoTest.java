package app.dao.bplus;

import java.util.HashMap;
import java.util.HashSet;

import bplus.keys.BPlusNodeKey;
import bplus.nodes.BPlusNode;
import exceptions.DataAccessException;

public class BPlusNodeDaoTest implements IBPlusNodeDao {

	
	private HashMap<BPlusNodeKey, BPlusNode> map;
	private BPlusNodeKey nextKey;
	
	BPlusNodeDaoTest() {
		nextKey = new BPlusNodeKey(0);
	}
	
	@Override
	public BPlusNode getNode(BPlusNodeKey id) throws DataAccessException {
		// TODO Auto-generated method stub
		BPlusNode node = map.get(id);
		
		// FIXME: agregarle una causa a la excepcion
		
		if (node == null) throw new DataAccessException();
		return node;
	}

	@Override
	public BPlusNodeKey insertNode(BPlusNode node) throws DataAccessException {
		// TODO Auto-generated method stub
		map.put(nextKey, node);
		
		// incrementar el nextKey
		nextKey.setValue(nextKey.getValue()+1);
		
		return nextKey;
	}

	@Override
	public void updateNode(BPlusNode node) throws DataAccessException {
		// TODO Auto-generated method stub

	}

}
