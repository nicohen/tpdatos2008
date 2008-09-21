package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import dto.DocumentDto;
import exceptions.PersistanceException;

public class DocumentPersistor extends AbstractPersistor<DocumentDto> {

	IntegerPersistor intPersistor = null;
	StringPersistor stringPersistor = null;
	
	public DocumentPersistor(int maxSize) {
		super(maxSize);
	}
	
	@Override
	public DocumentDto read(DataInputStream stream) throws PersistanceException {
		try {
			return new DocumentDto(stream.readInt(),"Focus");
		} catch (IOException e) {
			throw new PersistanceException("Error leyendo documento del archivo de DocumentsPersistor",e);
		}		
	}

	@Override
	public void write(DocumentDto element, DataOutputStream stream)
			throws PersistanceException {
		// TODO Auto-generated method stub
		
	}

}
