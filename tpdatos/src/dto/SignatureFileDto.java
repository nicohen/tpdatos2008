package dto;

public class SignatureFileDto {
	long signatureHash1;
	long signatureHash2;
	long signatureHash3;
	long signatureHash4;
	
	public SignatureFileDto(long signatureHash1,long signatureHash2,long signatureHash3,long signatureHash4) {
		this.signatureHash1=signatureHash1;
		this.signatureHash2=signatureHash2;
		this.signatureHash3=signatureHash3;
		this.signatureHash4=signatureHash4;
	}

	public long getSignatureHash1() {
		return signatureHash1;
	}

	public void setSignatureHash1(long signatureHash1) {
		this.signatureHash1 = signatureHash1;
	}

	public long getSignatureHash2() {
		return signatureHash2;
	}

	public void setSignatureHash2(long signatureHash2) {
		this.signatureHash2 = signatureHash2;
	}

	public long getSignatureHash3() {
		return signatureHash3;
	}

	public void setSignatureHash3(long signatureHash3) {
		this.signatureHash3 = signatureHash3;
	}

	public long getSignatureHash4() {
		return signatureHash4;
	}

	public void setSignatureHash4(long signatureHash4) {
		this.signatureHash4 = signatureHash4;
	}
	
	@Override
	public String toString() {
		return  String.valueOf(signatureHash1)+
				String.valueOf(signatureHash2)+
				String.valueOf(signatureHash3)+
				String.valueOf(signatureHash4);
	}
	
}
