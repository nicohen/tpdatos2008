package linkedblocks.codification;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.BitSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

import api.po.persistors.DistancesBlock;
import exceptions.PersistanceException;

public class GammaDistancesBlock implements DistancesBlock {

//	private byte[] byteArray;
	private int maxSize;
	private ByteArrayOutputStream stream = new ByteArrayOutputStream();
	
	// el modificador de acceso del constructor es package
	// para que solo las clases de este paquete puedan
	// instanciarla
	
	public GammaDistancesBlock( int maxsize ) {
		this.maxSize = maxsize;
	}
	
	public Iterator<Integer> decodeDistances() {
		List<Integer> lista = new LinkedList<Integer>();
		
		byte[] arry = this.toByteArray();
		
		int k = 0;
		while ( k < arry.length*8) {
			
			
			Integer distance = gammaDecode(arry, k);
			
			int nextByteOffset = gammaDecodeLength(arry, k);
			nextByteOffset = ((nextByteOffset + 8) / 8) * 8;
			lista.add(distance);
			k += nextByteOffset;
		}
		
		return lista.iterator();
	}

	public void encodeDistance(int distance) throws PersistanceException {
		byte[] gamma1 = gammaEncode(distance);
		
		if (stream.toByteArray().length + gamma1.length > this.maxSize ) {
			throw new PersistanceException("Encode Overflow");
		}
		
		// concatenar el nuevo byte array al q tenemos ahora
		try {
			stream.write(gamma1);
		} catch (IOException e) {
			// NOTE: esto no va a pasar
			throw new PersistanceException();
		}
	}

	public byte[] toByteArray() {
		return stream.toByteArray();
	}
	
	private byte[] gammaEncode(Integer key) { 
		BitSet cjto=new BitSet();
		int i,j=0;
		boolean flag;
		if (key==1) {
			cjto=new BitSet(key);
			cjto.set(0,true);
			return bitsetToByteArray(cjto);
		}
		
		Integer logaritmoEnBase2DeN = Integer.valueOf((int)Math.floor(Math.log(key)/Math.log(2)));
		for (i=0;i<logaritmoEnBase2DeN;i++) {
			cjto.set(i,false); //tanto unos como valor del log
		}
		//i++;
		cjto.set(i, true); //el 0 separador
		i++;
		Integer parteBinaria = Integer.valueOf((key-((int)Math.pow(2,logaritmoEnBase2DeN))));
		String binario= Integer.toBinaryString(parteBinaria);
		String aux = new String();
		if (binario.length()<logaritmoEnBase2DeN){
			
			for(int k=0;k<logaritmoEnBase2DeN-binario.length();k++)
			aux+="0";
			aux+=binario;
		}
		else
		aux+=binario;
		for (;i<logaritmoEnBase2DeN+logaritmoEnBase2DeN+1;i++) {
		
			if (aux.charAt(j)=='1')
			flag=true;
			else
			flag=false;
			cjto.set(i,flag);
			j++;
		}
		cjto.set(i,true);//se cierra con un 1
		return bitsetToByteArray(cjto);
	}
	
	
	private Integer gammaDecode(byte[] key, int init) { 
		BitSet set=bitsetFromByteArray(key,init);
		int i=0,contUnario=0,contBinario=0;
		String parteBinaria=new String();
		Integer valorEnBinario;
		while(!set.get(i)){ //leo hasta el primer 1
			contUnario++;
			i++;
		}
		if (contUnario==0) return 1;
		
		contBinario = contUnario;
		i++;//ignoro el 1
		for(int k=i;k<i+contBinario;k++){
			if(set.get(k))
			parteBinaria+="1";
			else
			parteBinaria+="0";
			
		}
		valorEnBinario=Integer.parseInt(parteBinaria, 2);
		return valorEnBinario+(int)Math.pow(2, contBinario); 
	}
	

	private BitSet bitsetFromByteArray(byte[] bytes, int init) {
        BitSet bits = new BitSet();
        for (int i=init; i<bytes.length*8; i++) {
            if ((bytes[i/8]&(1<<(i%8))) > 0) {
                bits.set(i-init);
            }
        }
        return bits;
    }
	
	private byte[] bitsetToByteArray(BitSet bits) {
        byte[] bytes = new byte[bits.length()/8+1];
        for (int i=0; i<bits.length(); i++) {
            if (bits.get(i)) {
                bytes[i/8] |= 1<<(i%8);
            }
        }
        return bytes;
    }
	private Integer gammaDecodeLength( byte key[], int init) {
		
		BitSet set=bitsetFromByteArray(key, init);
		int i=0,contUnario=0,contBinario=0;
		while(!set.get(i)){ //leo hasta el primer 1
			contUnario++;
			i++;
		}
		if (contUnario==0) return 1;
		contBinario = contUnario;
		return contBinario + contUnario + 1;
	}
	
}
