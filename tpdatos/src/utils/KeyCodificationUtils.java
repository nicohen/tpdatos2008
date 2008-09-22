package utils;

import java.util.BitSet;


public class KeyCodificationUtils {

	public static byte[] unarioEncode(Integer key) {
		
		BitSet cjto=new BitSet(key);
		
		for(int i=0;i<key;i++){
			cjto.set(i);
			if (i==key-1)
			cjto.set(i,false);
		}
		
		
		return toByteArray(cjto) ;
	}
	
	
	public static Integer unarioDecode(byte[] key) {
		return fromByteArray(key).length()+1;
	}
	
	public static byte[] gammaEncode(Integer key) { 
		Byte[] gamma = null;
		BitSet cjto=new BitSet();
		int i,j=0;
		boolean flag;
		if (key==1) {
			cjto=new BitSet(key);
			cjto.set(0,false);
			return toByteArray(cjto);
		}
		
		String gammaStr = "";
		Integer logaritmoEnBase2DeN = Integer.valueOf((int)Math.floor(Math.log(key)/Math.log(2)));
		for (i=0;i<logaritmoEnBase2DeN;i++) {
			cjto.set(i,true); //tanto unos como valor del log
		}
		i++;
		cjto.set(i, false); //el 0 separador
		Integer parteBinaria = Integer.valueOf((key-((int)Math.pow(2,logaritmoEnBase2DeN))));
		String binario= Integer.toBinaryString(parteBinaria);
		String aux = new String();
		if (parteBinaria<logaritmoEnBase2DeN){
			
			for(int k=0;k<logaritmoEnBase2DeN-1;k++)
			aux+="0";
			aux+=binario;
		}
		for (;i<logaritmoEnBase2DeN+logaritmoEnBase2DeN+1;i++) {
		
			if (aux.charAt(j)=='1')
			flag=true;
			else
			flag=false;
			cjto.set(i,flag);
			j++;
		}
		
		return toByteArray(cjto);
	}
	
	public static Integer gammaDecode(byte[] key) { 
		//TODO - Implementar gammaDecode
		BitSet set=fromByteArray(key);
		int i=0,contUnario=0,contBinario=0;
		String parteBinaria=new String();
		Integer valorEnBinario;
		while(set.get(i)){ //leo hasta el primer 0
			contUnario++;
			i++;
		}
		i++;//ignoro el 0
		for(int k=i;k<set.length();k++){
			contBinario++;
			if(set.get(k))
			parteBinaria+="1";
			else
			parteBinaria+="0";
			
		}
		valorEnBinario=Integer.parseInt(parteBinaria, 2);
		return valorEnBinario+(int)Math.pow(2, contBinario); 
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
	
	public static BitSet fromByteArray(byte[] bytes) {
        BitSet bits = new BitSet();
        for (int i=0; i<bytes.length*8; i++) {
            if ((bytes[bytes.length-i/8-1]&(1<<(i%8))) > 0) {
                bits.set(i);
            }
            else{
            	bits.set(i,false);
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
