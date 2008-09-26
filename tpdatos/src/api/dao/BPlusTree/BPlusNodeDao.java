package api.dao.BPlusTree;

import bplus.exceptions.NodeOverflowException;
import bplus.keys.BPlusNodeKey;
import bplus.nodes.BPlusIndexNode;
import bplus.nodes.BPlusLeafNode;
import bplus.nodes.BPlusNode;
import exceptions.DataAccessException;

public interface BPlusNodeDao {
	public void updateNode(BPlusNode node) throws DataAccessException,NodeOverflowException;
	public BPlusNodeKey insertNode(BPlusNode node) throws DataAccessException;
	public BPlusNode getNode(BPlusNodeKey id) throws DataAccessException;
}