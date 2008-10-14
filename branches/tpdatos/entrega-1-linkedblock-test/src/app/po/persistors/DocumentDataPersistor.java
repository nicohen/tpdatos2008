package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;

import api.po.persistors.SimplePersistor;
import exceptions.PersistanceException;

public class DocumentDataPersistor implements SimplePersistor<String> {

	SimpleStringPersistor stringPersistor = new SimpleStringPersistor();
	
	public DocumentDataPersistor() {
		super();
	}
	
	@Override
	public String read(DataInputStream stream) throws PersistanceException {
		return stringPersistor.read(stream);		
	}

	@Override
	public void write(String element, DataOutputStream stream)
			throws PersistanceException {
		stringPersistor.write(element, stream);//filename o titulo
	}
	
	@Override
	public int getElementSize(String element) {
		return stringPersistor.getElementSize(element);
	}

}
