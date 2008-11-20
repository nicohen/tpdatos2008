package signaturefiles.hash;

public class JSHash implements Hash {

	@Override
	public long getHash(String str) {
		long hash = 1315423911;
		
		for(int i = 0; i < str.length(); i++) {
			hash ^= ((hash << 5) + str.charAt(i) + (hash >> 2));
		}

		return hash;
	}

}
