package utils;

import java.util.BitSet;

public class KeyCodificationUtils {

	public static Byte[] unarioEncode(Integer key) {
		
		BitSet cjto=new BitSet(key);
		
		for(int i=0;i<cjto.length();i++){
			cjto.set(i,true);
			if (i==cjto.length())
			cjto.set(i,false);
		}
		
		
		return toByteArray(cjto) ;
	}
	
	
	public static Integer unarioDecode(Byte[] key) {
		return fromByteArray(key).length();
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
	
	public static Byte[] toByteArray(BitSet bits) {
        Byte[] bytes = new Byte[bits.length()/8+1];
        for (int i=0; i<bits.length(); i++) {
            if (bits.get(i)) {
                bytes[bytes.length-i/8-1] |= 1<<(i%8);
            }
        }
        return bytes;
    }
	
	public static BitSet fromByteArray(Byte[] bytes) {
        BitSet bits = new BitSet();
        for (int i=0; i<bytes.length*8; i++) {
            if ((bytes[bytes.length-i/8-1]&(1<<(i%8))) > 0) {
                bits.set(i);
            }
        }
        return bits;
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
