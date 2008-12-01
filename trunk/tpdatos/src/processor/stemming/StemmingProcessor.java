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
import dto.SuffixDto;
import exceptions.BusinessException;

public class StemmingProcessor {
	
	List<SuffixDto> suffixList = new ArrayList<SuffixDto>();;
	
	public StemmingProcessor(String listPath) throws BusinessException {
		prepareSuffixes(listPath);
		Collections.sort(suffixList);
	}
	
	@SuppressWarnings("deprecation")
	private void prepareSuffixes(String listPath) throws BusinessException {
		
	    File file = new File(listPath);
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
			throw new BusinessException("Error cargando lista de sufijos para stemming.");
		} catch (IOException e) {
			throw new BusinessException("Error cargando lista de sufijos para stemming.");
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
				
//				String finalString = str.substring( str.length() - suffix.length() );
				if ( str.endsWith( suffix.getSuffix() ) ) {
					return str.substring(0, str.length() - suffix.length() );
				}
			}
		}
		return str;
	}
}
