package test.bplus;

import java.util.HashSet;
import java.util.List;

import junit.framework.Assert;

import bplus.elements.BPlusElement;

public class BPlusNodeTestUtils {
	
	public static void assertElementsEquals(
			List<BPlusElement> elements1,
			List<BPlusElement> elements2) {
		
			HashSet<BPlusElement> set1 = new HashSet<BPlusElement>();
			HashSet<BPlusElement> set2 = new HashSet<BPlusElement>();
		
			for (BPlusElement e : elements1) {
				set1.add(e);
			}

			for (BPlusElement e : elements2) {
				set2.add(e);
			}

			for (BPlusElement e : elements1) {
				Assert.assertTrue( set2.contains(e) );
			}

			for (BPlusElement e : elements2) {
				Assert.assertTrue( set1.contains(e) );
			}

	}

}
