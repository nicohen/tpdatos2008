package test.processor;

import processor.stemming.StemmingProcessor;
import junit.framework.TestCase;


public class TestStemmerProcessor extends TestCase {
	private StemmingProcessor stemmer = new StemmingProcessor();
	
	public TestStemmerProcessor() {
		stemmer.addSuffix("ando");
		stemmer.addSuffix("endo");
		stemmer.addSuffix("ara");
		stemmer.addSuffix("emo");
		stemmer.addSuffix("aras");
		stemmer.addSuffix("emos");
	}
	
	private void eq( String str1, String str2 ) {
		String resultado = stemmer.stem(str1);
		assertEquals( resultado, str2 );
	}
	private void eq( String[] strs, String base) {
		for ( String str : strs ) {
			eq(str,base);
		}
	}
	
	public void test() {
		
		String[] str = {"programando",	"programara","programaras",	"programemos","programemo"}; 
		eq( str,"program");
		
		eq( "ando", "ando");
		eq( "emo", "emo");
		eq( "remos","remos");
		
	}
}
