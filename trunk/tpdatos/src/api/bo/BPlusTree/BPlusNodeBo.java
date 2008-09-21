package api.bo.BPlusTree;

import bplus.keys.BPlusNodeKey;
import bplus.nodes.BPlusNode;
import exceptions.DataAccessException;

public interface BPlusNodeBo {
	public abstract void updateNode(BPlusNode node) throws DataAccessException;
	public abstract BPlusNodeKey insertNode(BPlusNode node) throws DataAccessException;
	public abstract BPlusNode getNode(BPlusNodeKey id) throws DataAccessException;
}
