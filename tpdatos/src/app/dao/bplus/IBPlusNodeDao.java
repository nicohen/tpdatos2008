package app.dao.bplus;

import bplus.keys.BPlusNodeKey;
import bplus.nodes.BPlusNode;
import exceptions.DataAccessException;

public interface IBPlusNodeDao {

	public abstract void updateNode(BPlusNode node) throws DataAccessException;

	public abstract BPlusNodeKey insertNode(BPlusNode node)
			throws DataAccessException;

	public abstract BPlusNode getNode(BPlusNodeKey id)
			throws DataAccessException;

}