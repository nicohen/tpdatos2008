package signaturefiles.utils;

import utils.Constants;
import dto.SignatureFileDto;

public class SignatureUtils {

	private static long RSHash(String str) {
		int b = 378551;
	    int a = 63689;
	    long hash = 0;
	
	    for(int i = 0; i < str.length(); i++) {
	    	hash = hash * a + str.charAt(i);
	    	a = a * b;
		}
	
		return hash;
	}
	
	private static long JSHash(String str) {
		long hash = 1315423911;
	
		for(int i = 0; i < str.length(); i++) {
			hash ^= ((hash << 5) + str.charAt(i) + (hash >> 2));
		}

		return hash;
	}

	private static long PJWHash(String str) {
		long BitsInUnsignedInt = (long)(4 * 8);
		long ThreeQuarters     = (long)((BitsInUnsignedInt  * 3) / 4);
		long OneEighth         = (long)(BitsInUnsignedInt / 8);
		long HighBits          = (long)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
		long hash              = 0;
		long test              = 0;
	
		for(int i = 0; i < str.length(); i++) {
			hash = (hash << OneEighth) + str.charAt(i);
		
			if((test = hash & HighBits)  != 0) {
				hash = (( hash ^ (test >> ThreeQuarters)) & (~HighBits));
			}
		}
	
		return hash;
	}

	private static long ELFHash(String str) {
		long hash = 0;
		long x    = 0;
	
		for(int i = 0; i < str.length(); i++) {
			hash = (hash << 4) + str.charAt(i);
	
			if((x = hash & 0xF0000000L) != 0) {
				hash ^= (x >> 24);
			}
			hash &= ~x;
		}
	
		return hash;
	}

	//Devuelve el signature del termino ingresado
	public static SignatureFileDto getSignature(String word) {
		long[] firma= new long[Constants.SIGNATURE_SIZE];
		firma[0]=RSHash(word);
		firma[1]=JSHash(word);
		firma[2]=PJWHash(word);
		firma[3]=ELFHash(word);
		firma[4]=BKDRHash(word);
		firma[5]=SDBMHash(word);
		firma[6]=DJBHash(word);
		firma[7]=DEKHash(word);
		firma[8]=BPHash(word);
		firma[9]=FNVHash(word);
		firma[10]=APHash(word);
		
		return new SignatureFileDto(firma);
	}

	public static SignatureFileDto OR(SignatureFileDto sfDTO1, SignatureFileDto sfDTO2) {
		long[] firma= new long[11];
		long[] signature1=sfDTO1.getSignature();
		long[] signature2=sfDTO2.getSignature();    
		for (int i=0;i<Constants.SIGNATURE_SIZE;i++){
			firma[i]=signature1[i]|signature2[i];
		}
		return new SignatureFileDto(firma);
	}
	
	public static SignatureFileDto AND(SignatureFileDto sfDTO1, SignatureFileDto sfDTO2) {
		long[] firma= new long[11];
		long[] signature1=sfDTO1.getSignature();
		long[] signature2=sfDTO2.getSignature();    
		for (int i=0;i<Constants.SIGNATURE_SIZE;i++){
			firma[i]=signature1[i]&signature2[i];
		}
		return new SignatureFileDto(firma);
	}


   	private static long BKDRHash(String str) {
		long seed = 131; // 31 131 1313 13131 131313 etc..
		long hash = 0;

		for(int i = 0; i < str.length(); i++) {
			hash = (hash * seed) + str.charAt(i);
		}

		return hash;
	}
   
   	private static long SDBMHash(String str) {
		long hash = 0;

		for(int i = 0; i < str.length(); i++) {
			hash = str.charAt(i) + (hash << 6) + (hash << 16) - hash;
		}

		return hash;
	}

   	private static long DJBHash(String str)
   {
      long hash = 5381;

      for(int i = 0; i < str.length(); i++)
      {
         hash = ((hash << 5) + hash) + str.charAt(i);
      }

      return hash;
   }

   	private static long DEKHash(String str)
   {
      long hash = str.length();

      for(int i = 0; i < str.length(); i++)
      {
         hash = ((hash << 5) ^ (hash >> 27)) ^ str.charAt(i);
      }

      return hash;
   }

   	private static long BPHash(String str)
   {
      long hash = 0;

      for(int i = 0; i < str.length(); i++)
      {
         hash = hash << 7 ^ str.charAt(i);
      }

      return hash;
   }

   	private static long FNVHash(String str)
   {
      long fnv_prime = 0x811C9DC5;
      long hash = 0;

      for(int i = 0; i < str.length(); i++)
      {
      hash *= fnv_prime;
      hash ^= str.charAt(i);
      }

      return hash;
   }

   	private static long APHash(String str)
   {
      long hash = 0xAAAAAAAA;

      for(int i = 0; i < str.length(); i++)
      {
         if ((i & 1) == 0)
         {
            hash ^= ((hash << 7) ^ str.charAt(i) * (hash >> 3));
         }
         else
         {
            hash ^= (~((hash << 11) + str.charAt(i) ^ (hash >> 5)));
         }
      }

      return hash;
   }

	
   	public static SignatureFileDto getEmptySignature() {
		long[] firma= new long[Constants.SIGNATURE_SIZE];
		firma[0]=0;
		firma[1]=0;
		firma[2]=0;
		firma[3]=0;
		firma[4]=0;
		firma[5]=0;
		firma[6]=0;
		firma[7]=0;
		firma[8]=0;
		firma[9]=0;
		firma[10]=0;
		
		return new SignatureFileDto(firma);
	}
}
