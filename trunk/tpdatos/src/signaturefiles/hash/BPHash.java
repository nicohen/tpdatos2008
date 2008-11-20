package signaturefiles.hash;


public class BPHash implements Hash {

	@Override
	public long getHash(String str) {
		long hash = 0;

		for (int i = 0; i < str.length(); i++) {
			hash = hash << 7 ^ str.charAt(i);
		}

		return hash;
	}

}
