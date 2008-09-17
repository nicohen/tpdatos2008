package bplus;

import bplus.keys.BPlusNodeKey;
import bplus.nodes.BPlusIndexNode;
import bplus.nodes.BPlusLeafNode;
import bplus.nodes.BPlusNode;

public interface NodeHandler {
	public BPlusNode getNode(BPlusNodeKey nodeKey);
	public BPlusIndexNode newIndexNode(Integer nodeSize);
	public BPlusLeafNode newLeafNode(Integer nodeSize);
}
