package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;

import dto.DocumentDto;
import exceptions.PersistanceException;

public class DocumentDataPersistor extends AbstractPersistor<String> {

	VariableStringPersistor stringPersistor = new VariableStringPersistor();
	
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
	public int getDataSize() {
		// TODO Auto-generated method stub
		return 1;
	}

/*	public int getElementSize(DocumentDto element) {
		return integerPersistor.getElementSize(element.getDocumentId()) +
				stringPersistor.getElementSize(element.getFileName());
	}*/

}
