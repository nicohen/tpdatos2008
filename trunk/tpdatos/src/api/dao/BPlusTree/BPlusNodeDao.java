package api.dao.BPlusTree;

import bplus.exceptions.NodeOverflowException;
import bplus.keys.BPlusNodeKey;
import bplus.nodes.BPlusNode;
import exceptions.DataAccessException;

public interface BPlusNodeDao {
	public abstract void updateNode(BPlusNode node) throws DataAccessException,NodeOverflowException;
	public abstract BPlusNodeKey insertNode(BPlusNode node) throws DataAccessException;
	public abstract BPlusNode getNode(BPlusNodeKey id) throws DataAccessException;
}