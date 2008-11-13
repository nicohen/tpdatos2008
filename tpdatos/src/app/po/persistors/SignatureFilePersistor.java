package app.po.persistors;

import java.io.DataInputStream;
import java.io.DataOutputStream;

import utils.Constants;
import api.po.persistors.Persistor;
import dto.SignatureFileDto;
import exceptions.PersistanceException;

public class SignatureFilePersistor implements Persistor<SignatureFileDto> {

	LongPersistor longPersistor = new LongPersistor();
	IntegerPersistor intPersistor = new IntegerPersistor();
	
	public SignatureFilePersistor() {
		super();
	}
	
	@Override
	public int getDataSize() {
		return (longPersistor.getDataSize()*Constants.SIGNATURE_SIZE)+intPersistor.getDataSize();
	}

	@Override
	public int getElementSize(SignatureFileDto element) {
		return this.getDataSize();
	}

	@Override
	public SignatureFileDto read(DataInputStream stream)
			throws PersistanceException {
		int docId= intPersistor.read(stream);
		long[] firma= new long[Constants.SIGNATURE_SIZE];
		for(int i=0;i<Constants.SIGNATURE_SIZE;i++){
			firma[i]=longPersistor.read(stream);	
		}
		return new SignatureFileDto(docId,firma);	
	}

	@Override
	public void write(SignatureFileDto element, DataOutputStream stream)
			throws PersistanceException {
		intPersistor.write(element.getDocumentId(), stream);
		for(int i=0;i<Constants.SIGNATURE_SIZE;i++){
			longPersistor.write(element.getSignature()[i], stream);	
		}
	}


}
