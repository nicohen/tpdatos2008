package app.dao.bplus;

import api.po.persistors.Persistor;
import app.po.files.RelativeFile;
import app.po.persistors.BPlusNodePersistor;
import bplus.keys.BPlusNodeKey;
import bplus.nodes.BPlusNode;
import exceptions.DataAccessException;

public class BPlusNodeDao {
	
	private RelativeFile<BPlusNode> file;
	
	public BPlusNodeDao( ) throws DataAccessException {
		// TODO: hacer parametrizable el nombre
		
		Persistor<BPlusNode> persistor = new BPlusNodePersistor();
		file = new RelativeFile<BPlusNode>( "bplus.dat", persistor );
	}

	public void updateNode( BPlusNode node ) throws DataAccessException {
		file.update( node.getNodeKey().getValue(), node );
	}
	
	public BPlusNodeKey insertNode( BPlusNode node ) throws DataAccessException {
		// TODO
		return new BPlusNodeKey( file.add(node) );
	}
	
	public BPlusNode getNode( BPlusNodeKey id ) throws DataAccessException  {
		return file.get( id.getValue() );
	}
}
