package linkedblocks.codification;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.BitSet;
import java.util.Iterator;

import api.po.persistors.DistancesBlock;
import exceptions.PersistanceException;

public class GammaDistancesBlock implements DistancesBlock {

//	private byte[] byteArray;
	private int maxSize;
	private ByteArrayOutputStream stream = new ByteArrayOutputStream();
	
	// el modificador de acceso del constructor es package
	// para que solo las clases de este paquete puedan
	// instanciarla
	
	private class GammaIterator implements Iterator<Integer>{

		private Integer lastDecoded = 0;
		private boolean isLastDecoded = false;
		private int k = 0;
		private byte[] arry = GammaDistancesBlock.this.toByteArray();
		
		public boolean hasNext() {
			if (isLastDecoded) return true;
			decodeNext();
			return isLastDecoded;
		}

		public Integer next() {
			Integer aux = lastDecoded;
			isLastDecoded = false;
			return aux;
		}

		public void remove() {
			// TODO Auto-generated method stub
			
		}
		
		private void decodeNext() {
			if ( k < arry.length*8) {
				lastDecoded = gammaDecode(arry, k)-1;
				int nextByteOffset = gammaDecodeLength(arry, k);
				nextByteOffset = ((nextByteOffset + 8) / 8) * 8;
				k += nextByteOffset;

				isLastDecoded = true;
				
			} else {
				isLastDecoded = false;
			}
			
		}
		
	}
	
	public GammaDistancesBlock( int maxsize ) {
		this.maxSize = maxsize;
	}

	public GammaDistancesBlock( int maxsize, byte[] arry ) throws IOException {
		this.maxSize = maxsize;
		stream.write(arry);
	}

	public Iterator<Integer> decodeDistances() {
		return new GammaIterator();
	}

	public void encodeDistance(int distance) throws PersistanceException {
		byte[] gamma1 = gammaEncode(distance+1);
		
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
			return bitsetToByteArray(cjto,1);
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
		if (binario.length()<logaritmoEnBase2DeN){
			
			int zeros_length = logaritmoEnBase2DeN-binario.length();
			for(int k=0;k<zeros_length;k++) {
				binario="0"+binario;
			}
		}
		
		for (j=0;j<binario.length();j++) {
		
			if (binario.charAt(j)=='1') {
			flag=true;
			} else {
			flag=false;
			}
			
			cjto.set(i,flag);
			i++;
		}
		// poner un uno al final
		return bitsetToByteArray(cjto, (i+8)/8);
	}

	
	private Integer gammaDecode(byte[] key, int init) {
		
		byte[] bytes = key;
	
		int contUnario = 0;
		int contBinario = 0; 
		int parteUnaria = 1;
	
		int i = init;
		for (; ; ) {
	        if ((bytes[i/8]&(1<<(i%8))) > 0) {
	        	break;
	        } else {
				contUnario++;
	        	parteUnaria*=2;
				i++;
	        }
	    }
		
		if (contUnario==0) return 1;

		contBinario = contUnario;
		i++;//ignoro el 1
		
		int parteBinaria = (int)Math.pow(2, contBinario)-1;
		int deduccion = (int)Math.pow(2, contBinario)/2;

		for(int k=i;k<i+contBinario;k++){
	        if ((bytes[k/8]&(1<<(k%8))) > 0) {
	        } else {
	        	parteBinaria -= deduccion;
	        }
	        deduccion = deduccion/2;
		}
		
		
		return parteBinaria + parteUnaria;

	}
	
	private byte[] bitsetToByteArray(BitSet bits, int len) {
        byte[] bytes = new byte[len];
        for (int i=0; i<bits.length(); i++) {
            if (bits.get(i)) {
                bytes[i/8] |= 1<<(i%8);
            }
        }
        return bytes;
    }
	private Integer gammaDecodeLength( byte key[], int init) {
		

		int contUnario = 0;
		int contBinario = 0; 
	
		int i = init;
		for (; ; ) {
	        if ((key[i/8]&(1<<(i%8))) > 0) {
	        	break;
	        } else {
				contUnario++;
				i++;
	        }
	    }
		
		if (contUnario==0) return 1;
		contBinario = contUnario;
		return contBinario + contUnario + 1;
	}
	
}
