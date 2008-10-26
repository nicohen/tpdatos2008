package signaturefiles.utils;

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
		return new SignatureFileDto(
				RSHash(word),
				JSHash(word),
				PJWHash(word),
				ELFHash(word));
	}

	
	public static void main(String[] args) {
		System.out.println(getSignature("nicolas"));
	}

	public static SignatureFileDto OR(SignatureFileDto sfDTO1, SignatureFileDto sfDTO2) {
		return new SignatureFileDto(sfDTO1.getSignatureHash1()|sfDTO2.getSignatureHash1(),
				sfDTO1.getSignatureHash2()|sfDTO2.getSignatureHash2(),
				sfDTO1.getSignatureHash3()|sfDTO2.getSignatureHash3(),
				sfDTO1.getSignatureHash4()|sfDTO2.getSignatureHash4());
	}
	
	public static SignatureFileDto AND(SignatureFileDto sfDTO1, SignatureFileDto sfDTO2) {
		return new SignatureFileDto(sfDTO1.getSignatureHash1()&sfDTO2.getSignatureHash1(),
				sfDTO1.getSignatureHash2()&sfDTO2.getSignatureHash2(),
				sfDTO1.getSignatureHash3()&sfDTO2.getSignatureHash3(),
				sfDTO1.getSignatureHash4()&sfDTO2.getSignatureHash4());
	}


/*
   	private static long BKDRHash(String str) {
		long seed = 131; // 31 131 1313 13131 131313 etc..
		long hash = 0;

		for(int i = 0; i < str.length(); i++) {
			hash = (hash * seed) + str.charAt(i);
		}

		return hash;
	}
   
	public long SDBMHash(String str) {
		long hash = 0;

		for(int i = 0; i < str.length(); i++) {
			hash = str.charAt(i) + (hash << 6) + (hash << 16) - hash;
		}

		return hash;
	}

   public long DJBHash(String str)
   {
      long hash = 5381;

      for(int i = 0; i < str.length(); i++)
      {
         hash = ((hash << 5) + hash) + str.charAt(i);
      }

      return hash;
   }


   public long DEKHash(String str)
   {
      long hash = str.length();

      for(int i = 0; i < str.length(); i++)
      {
         hash = ((hash << 5) ^ (hash >> 27)) ^ str.charAt(i);
      }

      return hash;
   }


   public long BPHash(String str)
   {
      long hash = 0;

      for(int i = 0; i < str.length(); i++)
      {
         hash = hash << 7 ^ str.charAt(i);
      }

      return hash;
   }


   public long FNVHash(String str)
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

   public long APHash(String str)
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
*/	
	
	
	
	
	
	
	
}
