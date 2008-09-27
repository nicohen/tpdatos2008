package app.dao.bplus;

import api.dao.BPlusTree.BPlusNodeDao;
import api.po.persistors.Persistor;
import app.po.files.RelativeFile;
import app.po.persistors.BPlusNodePersistor;
import app.po.persistors.IntegerPersistor;
import bplus.keys.BPlusNodeKey;
import bplus.nodes.BPlusLeafNode;
import bplus.nodes.BPlusNode;
import exceptions.DataAccessException;

public class BPlusNodeDaoImp implements BPlusNodeDao {
	private static int NODE_SIZE_POSITION= 1;
	private static int TREE_ROOT_POSITION= 0;
	
	private RelativeFile<BPlusNode> file;
	private RelativeFile<Integer> metaFile;
	private int rootNode;
	
	public BPlusNodeDaoImp( String filename,int nodeSize ) throws DataAccessException {		
		Persistor<BPlusNode> persistor;
		Persistor<Integer> integerPersistor = new IntegerPersistor();
		metaFile= new RelativeFile<Integer>(filename+".meta",integerPersistor);
		if(metaFile.getSize()==0){
			persistor = new BPlusNodePersistor(nodeSize);
			this.rootNode=0;
			metaFile.add(0);
			metaFile.add(nodeSize);
			file = new RelativeFile<BPlusNode>( filename, persistor );
			this.rootNode= this.insertNode(new BPlusLeafNode()).getValue();
		}else{
			persistor = new BPlusNodePersistor(metaFile.get(NODE_SIZE_POSITION));
			file = new RelativeFile<BPlusNode>( filename, persistor );
			this.rootNode= this.metaFile.get(TREE_ROOT_POSITION);
		}		
	}

	public BPlusNodeDaoImp(int nodeSize) throws DataAccessException {
		this("bplus.dat", nodeSize);
	}

	/* (non-Javadoc)
	 * @see app.dao.bplus.IBPlusNodeDao#updateNode(bplus.nodes.BPlusNode)
	 */
	public void updateNode( BPlusNode node ) throws DataAccessException {
		file.update( node.getNodeKey().getValue(), node );
	}
	
	/* (non-Javadoc)
	 * @see app.dao.bplus.IBPlusNodeDao#insertNode(bplus.nodes.BPlusNode)
	 */
	public BPlusNodeKey insertNode( BPlusNode node ) throws DataAccessException {
		BPlusNodeKey index=	new BPlusNodeKey(file.add(node));
		node.setNodeKey(index);
		return index;
	}
	
	/* (non-Javadoc)
	 * @see app.dao.bplus.IBPlusNodeDao#getNode(bplus.keys.BPlusNodeKey)
	 */
	public BPlusNode getNode( BPlusNodeKey id ) throws DataAccessException  {
		BPlusNode node= file.get(id.getValue());
		node.setNodeKey(id);
		return node;
	}

	@Override
	public int getSize() {
		return this.file.getSize();
	}

	@Override
	public BPlusNode getRootNode(BPlusNodeKey plusNodeKey) throws DataAccessException {
		return this.file.get(this.rootNode);
	}

	@Override
	public void setRootNode(BPlusNodeKey plusNodeKey) throws DataAccessException {
		this.rootNode= plusNodeKey.getValue();
		this.metaFile.update(TREE_ROOT_POSITION, this.rootNode);
	}
}
