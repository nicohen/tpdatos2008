package signaturefiles.hash;

public class RSHash implements Hash {

	@Override
	public long getHash(String str) {
		int b = 378551;
		int a = 63689;
		long hash = 0;

		for (int i = 0; i < str.length(); i++) {
			hash = hash * a + str.charAt(i);
			a = a * b;
		}
		return hash;
	}

}
