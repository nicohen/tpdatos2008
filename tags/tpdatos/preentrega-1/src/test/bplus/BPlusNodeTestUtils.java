package test.bplus;

import java.util.List;

import junit.framework.Assert;
import bplus.elements.BPlusElement;

public class BPlusNodeTestUtils {

	
	public static void assertElementsEquals(
			List<BPlusElement> elements1,
			List<BPlusElement> elements2) {

			for (BPlusElement e : elements1) {
				Assert.assertTrue(elements2.contains(e));
			}

			for (BPlusElement e : elements2) {
				Assert.assertTrue(elements1.contains(e));
			}

	}

}
