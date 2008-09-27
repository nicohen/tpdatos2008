package utils.processor;

import java.util.ArrayList;
import java.util.List;

public class StemmerProcessor {
	
	
	private List<String> suffixList = new ArrayList<String>();
	
	public void addSuffix( String suffix ) {
		suffixList.add(suffix);
	}
	
	public String stem(String str) {
		for ( String suffix : suffixList ) {
			if ( str.substring( str.length() - suffix.length() ) == suffix ) {
				return str.substring(0, str.length() - suffix.length() );
			}
		}
		return str; 
	}
}
