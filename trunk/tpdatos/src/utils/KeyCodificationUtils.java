package utils;

import java.io.ByteArrayOutputStream;
import java.io.ObjectOutputStream;
import java.util.BitSet;


public class KeyCodificationUtils {

	public static byte[] unarioEncode(Integer key) {
		
		BitSet cjto=new BitSet(key);
		
		for(int i=0;i<key;i++){
			cjto.set(i,true);
			if (i==key-1)
			cjto.set(i,false);
		}
		
		
		return toByteArray(cjto) ;
	}
	
	
	public static Integer unarioDecode(byte[] key) {
		return fromByteArray(key).length();
	}
	/*
	public static Byte[] gammaEncode(Integer key) { 
		Byte[] gamma = null;
		BitSet cjto=new BitSet();
		int i,j=0;
		if (key==1) {
			cjto=new BitSet(key);
			cjto.set(0,false);
			return toByteArray(cjto);
		}
		
		String gammaStr = "";
		Integer logaritmoEnBase2DeN = Integer.valueOf((int)Math.floor(Math.log(key)/Math.log(2)));
		for (i=0;i<logaritmoEnBase2DeN;i++) {
			if (i==logaritmoEnBase2DeN)
			cjto.set(i,false);
			else
			cjto.set(i,true);
		}
		Integer parteBinaria = Integer.valueOf((key-((int)Math.pow(2,logaritmoEnBase2DeN))));
		String binario= Integer.toBinaryString(parteBinaria);
		for (;i<logaritmoEnBase2DeN+binario.length();++i) {
			cjto.set(i,Boolean.parseBoolean(binario.substring(j, j+1)));
			j++;
		}
		
		return toByteArray(cjto);
	}
	*/
	public static Integer gammaDecode(Byte[] key) { 
		//TODO - Implementar gammaDecode
		return null; 
	}
	
	public static byte[] toByteArray(BitSet bits) {
        byte[] bytes = new byte[bits.length()/8+1];
        for (int i=0; i<bits.length(); i++) {
            if (bits.get(i)) {
                bytes[bytes.length-i/8-1] |= 1<<(i%8);
            }
        }
        return bytes;
    }
	/*
	public static byte[] toByteArray(BitSet bitSet) {
	     ByteArrayOutputStream baos = new ByteArrayOutputStream(bitSet.size());
	     try {
	       ObjectOutputStream oos = new ObjectOutputStream(baos);
	       oos.writeObject(bitSet);
	     }
	     catch (Exception ex) {
	       ex.printStackTrace();
	     }
	     return baos.toByteArray();
	  }
	*/
	public static BitSet fromByteArray(byte[] bytes) {
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
