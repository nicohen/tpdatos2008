package test.processor;

import utils.processor.StemmerProcessor;
import junit.framework.TestCase;


public class TestStemmerProcessor extends TestCase {
	private StemmerProcessor stemmer = new StemmerProcessor();
	
	public TestStemmerProcessor() {
		stemmer.addSuffix("ando");
		stemmer.addSuffix("endo");
		stemmer.addSuffix("ara");
		stemmer.addSuffix("emo");
		stemmer.addSuffix("aras");
		stemmer.addSuffix("emos");
	}
	
	void eq( String str1, String str2 ) {
		assertEquals( stemmer.digest(str1), str2 );
	}
	void test() {
		eq( "programando","program");
		
	}
}
