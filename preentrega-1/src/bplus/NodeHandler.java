package bplus;

import bplus.exceptions.NodeNotFoundException;
import bplus.exceptions.NodeOverflowException;
import bplus.keys.BPlusNodeKey;
import bplus.nodes.BPlusIndexNode;
import bplus.nodes.BPlusLeafNode;
import bplus.nodes.BPlusNode;

public interface NodeHandler {
	public BPlusNode getNode(BPlusNodeKey nodeKey) throws NodeNotFoundException;
	public BPlusIndexNode newIndexNode(Integer nodeSize);
	public BPlusLeafNode newLeafNode(Integer nodeSize);
	public void updateNode(BPlusNode node) throws NodeOverflowException;
}
