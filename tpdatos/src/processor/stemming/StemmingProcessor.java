package processor.stemming;

import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import processor.utils.DigesterUtils;
import utils.Constants;
import dto.SuffixDto;

public class StemmingProcessor {
	
	List<SuffixDto> suffixList = new ArrayList<SuffixDto>();;
	
	public StemmingProcessor() {
		prepareSuffixes();
		Collections.sort(suffixList);
		System.out.println(suffixList.toString());
	}
	
	@SuppressWarnings("deprecation")
	private void prepareSuffixes() {
		
	    File file = new File(Constants.FILE_STEMMING);
	    FileInputStream fis = null;
	    BufferedInputStream bis = null;
	    DataInputStream dis = null;

	    try {
	    	fis = new FileInputStream(file);
			bis = new BufferedInputStream(fis);
			dis = new DataInputStream(bis);
			
			while (dis.available() != 0) {
				String rawSuffix = dis.readLine();
				String suffix = DigesterUtils.formatText(rawSuffix);
				if(!suffixList.contains(new SuffixDto(suffix))) {
					suffixList.add(new SuffixDto(suffix));
				}
			}

			fis.close();
			bis.close();
			dis.close();

		} catch (FileNotFoundException e) {
		  e.printStackTrace();
		} catch (IOException e) {
		  e.printStackTrace();
		}		
	}

	public void addSuffix(String suffix) {
		suffixList.add(new SuffixDto(suffix));
		Collections.sort(suffixList);
	}
	
	public String stem(String str) {
		if(str.length()>3) {
			for ( SuffixDto suffix : suffixList ) {
				if ( str.length() - suffix.length() < 3 ) continue;
				
				String finalString = str.substring( str.length() - suffix.length() );
				if ( finalString.equals( suffix.getSuffix() ) ) {
//					if (str.length() - suffix.length() >= 3) {
						return str.substring(0, str.length() - suffix.length() );
//					}
				}
			}
		}
		return str;
	}
}
