package signaturefiles.utils;

import java.util.ArrayList;
import java.util.List;

import signaturefiles.hash.APHash;
import signaturefiles.hash.BKDRHash;
import signaturefiles.hash.BPHash;
import signaturefiles.hash.DEKHash;
import signaturefiles.hash.DJBHash;
import signaturefiles.hash.ELFHash;
import signaturefiles.hash.FNVHash;
import signaturefiles.hash.Hash;
import signaturefiles.hash.JSHash;
import signaturefiles.hash.PJWHash;
import signaturefiles.hash.RSHash;
import signaturefiles.hash.SDBMHash;
import utils.Constants;
import dto.SignatureFileDto;

public class SignatureUtils {
	
	//Devuelve el signature del termino ingresado
	public static SignatureFileDto getSignature(String word, int length) {
		long[] firma= new long[length];
		for(int i=0;i<length;i++){
			firma[i]=hashes.get(i).getHash(word);
		}		
		return new SignatureFileDto(firma);
	}

	public static SignatureFileDto OR(SignatureFileDto sfDTO1, SignatureFileDto sfDTO2) {
		long[] firma= new long[11];
		long[] signature1=sfDTO1.getSignature();
		long[] signature2=sfDTO2.getSignature();    
		for (int i=0;i<Constants.SIGNATURE_SIZE;i++){
			firma[i]=signature1[i]|signature2[i];
		}
		return new SignatureFileDto(sfDTO1.getDocumentId(),firma);
	}
	
	public static SignatureFileDto AND(SignatureFileDto sfDTO1, SignatureFileDto sfDTO2) {
		long[] firma= new long[11];
		long[] signature1=sfDTO1.getSignature();
		long[] signature2=sfDTO2.getSignature();    
		for (int i=0;i<Constants.SIGNATURE_SIZE;i++){
			firma[i]=signature1[i]&signature2[i];
		}
		return new SignatureFileDto(sfDTO1.getDocumentId(),firma);
	}
   
   	public static SignatureFileDto getEmptySignature(Integer docId, int length) {
		long[] firma= new long[length];
		for(int i=0; i<length; i++){
			firma[i]=0;
		}
		return new SignatureFileDto(docId,firma);
	}
   	
   	private static List<Hash> hashes;
   	static {
   		hashes= new ArrayList<Hash>(11);
		hashes.add(new RSHash());
		hashes.add(new JSHash());
		hashes.add(new PJWHash());
		hashes.add(new ELFHash());
		hashes.add(new BKDRHash());
		hashes.add(new SDBMHash());
		hashes.add(new DJBHash());
		hashes.add(new DEKHash());
		hashes.add(new BPHash());
		hashes.add(new FNVHash());
		hashes.add(new APHash());
   	}
}
