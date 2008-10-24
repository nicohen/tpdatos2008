package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;

import api.po.persistors.Persistor;
import dto.SignatureFileDto;
import exceptions.PersistanceException;

public class SignatureFilePersistor implements Persistor<SignatureFileDto> {

	LongPersistor longPersistor = new LongPersistor();
	
	public SignatureFilePersistor() {
		super();
	}
	
	@Override
	public int getDataSize() {
		return longPersistor.getDataSize()*4;
	}

	@Override
	public int getElementSize(SignatureFileDto element) {
		return this.getDataSize();
	}

	@Override
	public SignatureFileDto read(DataInputStream stream)
			throws PersistanceException {
		return new SignatureFileDto(
				longPersistor.read(stream),
				longPersistor.read(stream),
				longPersistor.read(stream),
				longPersistor.read(stream));	
	}

	@Override
	public void write(SignatureFileDto element, DataOutputStream stream)
			throws PersistanceException {
		longPersistor.write(element.getSignatureHash1(), stream);
		longPersistor.write(element.getSignatureHash2(), stream);
		longPersistor.write(element.getSignatureHash3(), stream);
		longPersistor.write(element.getSignatureHash4(), stream);
	}


}
