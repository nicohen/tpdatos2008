package processor.stopwords;

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
import dto.WordDto;

public class StopwordsProcessor {

	List<WordDto> stopwords = null;
	
	public StopwordsProcessor() {
		prepareStopwords();
		Collections.sort(stopwords);
	}
	
	@SuppressWarnings("deprecation")
	public void prepareStopwords()  {
		stopwords = new ArrayList<WordDto>();
		
	    File file = new File(Constants.FILE_STOPWORDS);
	    FileInputStream fis = null;
	    BufferedInputStream bis = null;
	    DataInputStream dis = null;

	    try {
	    	fis = new FileInputStream(file);
			bis = new BufferedInputStream(fis);
			dis = new DataInputStream(bis);
			
			while (dis.available() != 0) {
				String rawStopword = dis.readLine();
				List<String> words = new ArrayList<String>(); 
				String[] dividedStopWord = rawStopword.split(" ");
				for (int i=0;i<dividedStopWord.length;i++) {
					words.add(DigesterUtils.formatText(dividedStopWord[i]));
				}
				WordDto wDto = new WordDto(words);
				stopwords.add(wDto);
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

	public List<WordDto> getStopwords() {
		return stopwords;
	}

	public boolean isStopword(String word) {
		return stopwords.contains(word); 
	}
	
}
