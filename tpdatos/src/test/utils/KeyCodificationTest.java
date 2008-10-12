package test.utils;

import junit.framework.TestCase;
import linkedblocks.utils.KeyCodificationUtils;

public class KeyCodificationTest extends TestCase {

//	public void testUnarioEncode() {
//		Byte[] unario1 = KeyCodificationUtils.unarioEncode("1");
//		assertEquals(48,(char)gamma1[0].intValue());	
//	}
	
	public void _testNumber(Integer num1) {
		byte[] gamma1 = KeyCodificationUtils.gammaEncode(num1);
		Integer size1=KeyCodificationUtils.gammaDecode(gamma1);
		assertEquals(size1,num1);
	}
	
	public void test() {
		for (Integer i = 1; i < 1000; i++) {
			_testNumber(i);
		}
	}
	
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
		Integer num1=0;
		byte[] gamma1 = KeyCodificationUtils.gammaEncode(num1);
		Integer size1=KeyCodificationUtils.gammaDecode(gamma1);
		assertEquals(size1,num1);
		}
}

