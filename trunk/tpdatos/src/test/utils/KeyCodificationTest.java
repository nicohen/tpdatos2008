package test.utils;

import java.util.BitSet;

import junit.framework.TestCase;
import utils.KeyCodificationUtils;

public class KeyCodificationTest extends TestCase {

//	public void testUnarioEncode() {
//		Byte[] unario1 = KeyCodificationUtils.unarioEncode("1");
//		assertEquals(48,(char)gamma1[0].intValue());	
//	}
	
	public void testUnaryEncode() {
		Integer num1=8,num2=5;
		//11111110
		byte[] gamma1 = KeyCodificationUtils.unarioEncode(num1);
		Integer size1=KeyCodificationUtils.unarioDecode(gamma1);
		size1+=1;
		assertEquals(size1,num1);
		//11110
		byte[] gamma2 = KeyCodificationUtils.unarioEncode(num2);
		BitSet set=new BitSet();
		Integer size2=KeyCodificationUtils.unarioDecode(gamma2);
		size2+=1;
		assertEquals(size2,num2);
		}
	public void testGammaEncode(){
		Integer num1=9,num2=5;
		//11111110
		byte[] gamma1 = KeyCodificationUtils.gammaEncode(num1);
		Integer size1=KeyCodificationUtils.gammaDecode(gamma1);
		//size1+=1;
		//assertEquals(size1,num1);
		}
}

