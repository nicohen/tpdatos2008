package app.dao.bplus;

import api.dao.BPlusTree.BPlusNodeDao;
import api.po.persistors.Persistor;
import app.po.files.RelativeFile;
import app.po.persistors.BPlusNodePersistor;
import bplus.keys.BPlusNodeKey;
import bplus.nodes.BPlusNode;
import exceptions.DataAccessException;

public class BPlusNodeDaoImp implements BPlusNodeDao {
	
	private RelativeFile<BPlusNode> file;
	
	public BPlusNodeDaoImp( String filename ) throws DataAccessException {
		// TODO: hacer parametrizable el nombre
		
		Persistor<BPlusNode> persistor = new BPlusNodePersistor();
		file = new RelativeFile<BPlusNode>( filename, persistor );
	}

	public BPlusNodeDaoImp(  ) throws DataAccessException {
		// TODO: hacer parametrizable el nombre
		
		Persistor<BPlusNode> persistor = new BPlusNodePersistor();
		file = new RelativeFile<BPlusNode>( "bplus.dat", persistor );
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
		// TODO
		return new BPlusNodeKey( file.add(node) );
	}
	
	/* (non-Javadoc)
	 * @see app.dao.bplus.IBPlusNodeDao#getNode(bplus.keys.BPlusNodeKey)
	 */
	public BPlusNode getNode( BPlusNodeKey id ) throws DataAccessException  {
		return file.get( id.getValue() );
	}
}
