package utils;

public class KeyCodificationUtils {

	public static Byte[] unarioEncode(String key) {
		Integer longitud = key.length();
		Byte[] unario = new Byte[longitud];
		for (int i=0;i<longitud-1;i++) {
			unario[i] = 0;
		}
		unario[longitud]=1;
		return unario;
	}
	
	public static String unarioDecode(Byte[] key) {
		return String.valueOf(key.length);
	}
	
	public static Byte[] gammaEncode(Integer key) { 
		Byte[] gamma = null;
		if (key==1) {
			gamma = new Byte[1];
			gamma[0]=48;
			return gamma;
		}
		String gammaStr = "";
		String logaritmoEnBase2DeN = String.valueOf((int)Math.floor(Math.log(key)/Math.log(2)));
		for (int i=0;i<Integer.parseInt(logaritmoEnBase2DeN);i++) {
			gammaStr += 1;	
		}
		gammaStr += 0;
		String ultimos = String.valueOf((key-((int)Math.pow(2,Integer.parseInt(logaritmoEnBase2DeN)))));
		for (int i=0;i<Integer.parseInt(logaritmoEnBase2DeN)-ultimos.length();i++) {
			gammaStr+=0;
		}
		for (int i=0;i<ultimos.length();i++) {
			gammaStr+=ultimos.charAt(i);
		}
		gamma = new Byte[gammaStr.length()];
		for (int i=0;i<gammaStr.length();i++) {
			gamma[i]=(byte)gammaStr.charAt(i);
		}
		return gamma;
	}
	
	public static Integer gammaDecode(Byte[] key) { 
		//TODO - Implementar gammaDecode
		return null; 
	}
	
//	public static Byte[] deltaEncode(Integer key) { 
//		//TODO - Implementar deltaEncode
//		return null; 
//	}
//	
//	public static Integer deltaDecode(Byte[] key) { 
//		//TODO - Implementar deltaDecode
//		return null; 
//	}
	
}
