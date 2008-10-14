package app.dao.bplus;

import utils.Constants;
import api.dao.BPlusTree.BPlusNodeDao;
import api.po.files.File;
import api.po.persistors.Persistor;
import app.po.files.ReadingBufferedFile;
import app.po.files.RelativeFile;
import app.po.persistors.BPlusNodePersistor;
import app.po.persistors.IntegerPersistor;
import bplus.exceptions.NodeOverflowException;
import bplus.keys.BPlusNodeKey;
import bplus.nodes.BPlusLeafNode;
import bplus.nodes.BPlusNode;
import exceptions.DataAccessException;
import exceptions.PersistanceException;

public class BPlusNodeDaoImp implements BPlusNodeDao {
	private static int NODE_SIZE_POSITION= 1;
	private static int TREE_ROOT_POSITION= 0;
	
	private File<BPlusNode> file;
	private File<Integer> metaFile;
	private BPlusNodeKey rootNode;
	
	public BPlusNodeDaoImp( String filename,int nodeSize ) throws DataAccessException {		
		Persistor<BPlusNode> persistor;
		Persistor<Integer> integerPersistor = new IntegerPersistor();
		metaFile= 
			new ReadingBufferedFile<Integer> (
			new RelativeFile<Integer>(filename+".meta",integerPersistor)
			,integerPersistor);
		if(metaFile.getSize()==0){
			persistor = new BPlusNodePersistor(nodeSize);
			this.rootNode=new BPlusNodeKey(0);
			try {
				metaFile.add(0);
				metaFile.add(nodeSize);
			} catch (PersistanceException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			file = 
				new ReadingBufferedFile<BPlusNode>( 
				new RelativeFile<BPlusNode>( filename, persistor ),
				persistor
				
				);
			try {
				this.rootNode= this.insertNode(new BPlusLeafNode());
			} catch (NodeOverflowException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}else{
			persistor = new BPlusNodePersistor(metaFile.get(NODE_SIZE_POSITION));
			file =
				new ReadingBufferedFile<BPlusNode>( 
				new RelativeFile<BPlusNode>( filename, persistor ),
				persistor );
			
			this.rootNode= new BPlusNodeKey(this.metaFile.get(TREE_ROOT_POSITION));
		}		
	}

	public BPlusNodeDaoImp(int nodeSize) throws DataAccessException {
		this(Constants.BPLUS_FILE_PATH, nodeSize);
	}

	/* (non-Javadoc)
	 * @see app.dao.bplus.IBPlusNodeDao#updateNode(bplus.nodes.BPlusNode)
	 */
	public void updateNode( BPlusNode node ) throws DataAccessException,NodeOverflowException{
		try {
			file.update( node.getNodeKey().getValue(), node );
		} catch (PersistanceException e) {
			throw new NodeOverflowException(e);
		}
	}
	
	/* (non-Javadoc)
	 * @see app.dao.bplus.IBPlusNodeDao#insertNode(bplus.nodes.BPlusNode)
	 */
	public BPlusNodeKey insertNode( BPlusNode node ) throws DataAccessException, NodeOverflowException {
		try {
			BPlusNodeKey index=	new BPlusNodeKey(file.add(node));
			node.setNodeKey(index);
			return index;
		} catch (PersistanceException e) {
			// TODO Auto-generated catch block
			throw new NodeOverflowException(e);
		}
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
	public BPlusNode getRootNode() throws DataAccessException {
		BPlusNode node= file.get(this.rootNode.getValue());
		node.setNodeKey(this.rootNode);
		return node;
	}

	@Override
	public void setRootNode(BPlusNodeKey plusNodeKey) throws DataAccessException {
		this.rootNode= plusNodeKey;
		try {
			this.metaFile.update(TREE_ROOT_POSITION, this.rootNode.getValue());
		} catch (PersistanceException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
