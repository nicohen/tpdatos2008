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
			if ( str.length() - suffix.length() <= 0 ) continue;
			
			String finalString = str.substring( str.length() - suffix.length() );
			if ( finalString.equals( suffix ) ) {
				if (str.length() - suffix.length() > 3) {
					return str.substring(0, str.length() - suffix.length() );
				}
			}
		}
		return str; 
	}
}
