package api.dao.BPlusTree;

import bplus.exceptions.NodeOverflowException;
import bplus.keys.BPlusNodeKey;
import bplus.nodes.BPlusNode;
import exceptions.DataAccessException;

public interface BPlusNodeDao {
	public void updateNode(BPlusNode node) throws DataAccessException,NodeOverflowException;
	public BPlusNodeKey insertNode(BPlusNode node) throws DataAccessException, NodeOverflowException;
	public BPlusNode getNode(BPlusNodeKey id) throws DataAccessException;
	public int getSize();
	public void setRootNode(BPlusNodeKey plusNodeKey) throws DataAccessException;
	public BPlusNode getRootNode() throws DataAccessException;
}