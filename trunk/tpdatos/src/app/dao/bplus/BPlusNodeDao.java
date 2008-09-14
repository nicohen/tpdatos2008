package app.dao.bplus;

import api.po.persistors.Persistor;
import app.po.files.RelativeFile;
import app.po.persistors.BPlusNodePersistor;
import bplus.nodes.BPlusNode;
import exceptions.DataAccessException;

public class BPlusNodeDao {
	
	private RelativeFile<BPlusNode> file;
	
	public BPlusNodeDao( ) throws DataAccessException {
		// TODO: hacer parametrizable el nombre
		
		Persistor<BPlusNode> persistor = new BPlusNodePersistor();
		file = new RelativeFile<BPlusNode>( "bplus.dat", persistor );
	}

	public void insertNode( BPlusNode node ) {
			node
	}
	
	public BPlusNode getNode( BPlusNodeKey id )  {
		
	}
}
