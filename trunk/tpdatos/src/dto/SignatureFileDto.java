package dto;

public class SignatureFileDto {
	long[] signature;
	
	public SignatureFileDto(long[] signatureHash) {
		signature=signatureHash;
	}

	public long[] getSignature() {
		return signature;
	}

	public void setSignature(long[] signatures) {
		this.signature = signatures;
	}
	
	@Override
	public boolean equals(Object obj) {
		if (obj instanceof SignatureFileDto) {
			SignatureFileDto sf = (SignatureFileDto) obj;
			int length= this.signature.length;
			int i=1;
			boolean equal=this.signature[0]==sf.signature[0];
			while(equal&&i<length){
				equal=this.signature[i]==sf.signature[i];
				i++;
			}
			return equal;
		}
		return super.equals(obj);
	}
	
	@Override
	public String toString() {
		StringBuilder sb= new StringBuilder();
		for(int i=0;i<this.signature.length;i++){
			sb.append(Long.toHexString(this.signature[i]));
		}
		return sb.toString();
	}
	
}
