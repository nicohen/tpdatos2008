package test.utils;

import junit.framework.TestCase;
import utils.KeyCodificationUtils;

public class KeyCodificationTest extends TestCase {

//	public void testUnarioEncode() {
//		Byte[] unario1 = KeyCodificationUtils.unarioEncode("1");
//		assertEquals(48,(char)gamma1[0].intValue());	
//	}
	
	public void testUnaryEncode() {
		Integer num1=8,num2=5;
		byte[] gamma1 = KeyCodificationUtils.unarioEncode(num1);
		Integer size1=KeyCodificationUtils.unarioDecode(gamma1);
		assertEquals(size1,num1);
		byte[] gamma2 = KeyCodificationUtils.unarioEncode(num2);
		Integer size2=KeyCodificationUtils.unarioDecode(gamma2);
		assertEquals(size2,num2);
		}
	public void testGammaEncode(){
		Integer num1=15;
		byte[] gamma1 = KeyCodificationUtils.gammaEncode(num1);
		Integer size1=KeyCodificationUtils.gammaDecode(gamma1);
		assertEquals(size1,num1);
		}
}
