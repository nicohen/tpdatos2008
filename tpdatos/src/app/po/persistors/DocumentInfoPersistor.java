package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;

import dto.DocumentDto;
import exceptions.PersistanceException;

public class DocumentInfoPersistor extends AbstractPersistor<DocumentDto> {

	IntegerPersistor integerPersistor = new IntegerPersistor();
	
	public DocumentInfoPersistor() {
		super();
	}
	
	@Override
	public DocumentDto read(DataInputStream stream) throws PersistanceException {
		return new DocumentDto(integerPersistor.read(stream),integerPersistor.read(stream));		
	}

	@Override
	public void write(DocumentDto element, DataOutputStream stream)
			throws PersistanceException {
		integerPersistor.write(element.getOffset(), stream);//offset a secuencial
		integerPersistor.write(element.getFileName().length(), stream);//longitud a leer
	}

	@Override
	public int getDataSize() {
		// TODO Auto-generated method stub
		return 0;
	}

/*	public int getElementSize(DocumentDto element) {
		return integerPersistor.getElementSize(element.getDocumentId()) +
				stringPersistor.getElementSize(element.getFileName());
	}*/

}
