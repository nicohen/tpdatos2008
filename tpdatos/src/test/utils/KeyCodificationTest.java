package test.utils;

import junit.framework.TestCase;
import utils.KeyCodificationUtils;

public class KeyCodificationTest extends TestCase {

//	public void testUnarioEncode() {
//		Byte[] unario1 = KeyCodificationUtils.unarioEncode("1");
//		assertEquals(48,(char)gamma1[0].intValue());	
//	}
	
	public void testGammaEncode() {
		//0
		Byte[] gamma1 = KeyCodificationUtils.gammaEncode(1);
		assertEquals(48,(char)gamma1[0].intValue());	

		//100
		Byte[] gamma2 = KeyCodificationUtils.gammaEncode(2);
		assertEquals(49,gamma2[0].intValue());	
		assertEquals(48,gamma2[1].intValue());
		assertEquals(48,gamma2[2].intValue());

		//101
		Byte[] gamma3 = KeyCodificationUtils.gammaEncode(3);
		assertEquals(49,gamma3[0].intValue());	
		assertEquals(48,gamma3[1].intValue());
		assertEquals(49,gamma3[2].intValue());

		//11000
		Byte[] gamma4 = KeyCodificationUtils.gammaEncode(4);
		assertEquals(49,gamma4[0].intValue());	
		assertEquals(49,gamma4[1].intValue());
		assertEquals(48,gamma4[2].intValue());
		assertEquals(48,gamma4[3].intValue());
		assertEquals(48,gamma4[4].intValue());

		//FIXME: Esta prueba falla, deberia devolver 11111010000
		Byte[] gamma48 = KeyCodificationUtils.gammaEncode(48);
		assertEquals(49,gamma48[0].intValue());	
		assertEquals(49,gamma48[1].intValue());
		assertEquals(49,gamma48[2].intValue());
		assertEquals(49,gamma48[3].intValue());
		assertEquals(49,gamma48[4].intValue());
		assertEquals(48,gamma48[5].intValue());
		assertEquals(49,gamma48[6].intValue());
		assertEquals(48,gamma48[7].intValue());
		assertEquals(48,gamma48[8].intValue());
		assertEquals(48,gamma48[9].intValue());
		assertEquals(48,gamma48[10].intValue());
	}
}
