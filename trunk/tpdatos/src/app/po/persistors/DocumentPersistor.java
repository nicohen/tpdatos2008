package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;

import dto.DocumentDto;
import exceptions.PersistanceException;

public class DocumentPersistor extends AbstractPersistor<DocumentDto> {

	IntegerPersistor integerPersistor = new IntegerPersistor();
	StringPersistor stringPersistor = new StringPersistor(50);
	
	public DocumentPersistor(int maxSize) {
		super(maxSize);
	}
	
	@Override
	public DocumentDto read(DataInputStream stream) throws PersistanceException {
		return new DocumentDto(integerPersistor.read(stream),stringPersistor.read(stream));		
	}

	@Override
	public void write(DocumentDto element, DataOutputStream stream)
			throws PersistanceException {
		integerPersistor.write(element.getDocumentId(), stream);
		stringPersistor.write(element.getFileName(), stream);
	}

	@Override
	public int getElementSize(DocumentDto element) {
		return integerPersistor.getElementSize(element.getDocumentId()) +
				stringPersistor.getElementSize(element.getFileName());
	}

}
