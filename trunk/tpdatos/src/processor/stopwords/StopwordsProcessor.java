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
import exceptions.BusinessException;

public class StopwordsProcessor {

	List<WordDto> stopwords = null;
	
	public StopwordsProcessor(String listPath) throws BusinessException {
		prepareStopwords(listPath);
		Collections.sort(stopwords);
	}
	
	@SuppressWarnings("deprecation")
	public void prepareStopwords(String listPath) throws BusinessException  {
		stopwords = new ArrayList<WordDto>();
		
	    File file = new File(listPath);
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
			throw new BusinessException("Error cargando lista de stopwords.");
		} catch (IOException e) {
			throw new BusinessException("Error cargando lista de stopwords.");
		}		
		
	}

	public List<WordDto> getStopwords() {
		return stopwords;
	}

	public boolean isStopword(String word) {
		List<String> words = new ArrayList<String>();
		for(String wordSplit : word.split(" ")) {
			words.add(wordSplit);
		}
		return stopwords.contains(new WordDto(words));
	}
	
}
