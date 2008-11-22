package test.processor;

import junit.framework.TestCase;
import processor.stemming.StemmingProcessor;
import utils.Constants;
import exceptions.BusinessException;


public class TestStemmerProcessor extends TestCase {
	private StemmingProcessor stemmer;
	
	public TestStemmerProcessor() {
		stemmer.addSuffix("ando");
		stemmer.addSuffix("endo");
		stemmer.addSuffix("ara");
		stemmer.addSuffix("emo");
		stemmer.addSuffix("aras");
		stemmer.addSuffix("emos");
		try {
			stemmer = new StemmingProcessor(Constants.FILE_STEMMING);
		} catch (BusinessException e) {
			e.printStackTrace();
		}
	}
	
	private void eq( String str1, String str2 ) {
		assertEquals(stemmer.stem(str1),str2);
	}
	private void eq( String[] strs, String base) {
		for ( String str : strs ) {
			eq(str,base);
		}
	}
	
	public void test() {
		
		String[] str = {"programando",	"programara","programaras",	"programemos","programemo"}; 
		eq( str,"program");
		
		eq( "ando", "and");
		eq( "emo", "emo");
		eq( "remos","remos");
		
	}
}
