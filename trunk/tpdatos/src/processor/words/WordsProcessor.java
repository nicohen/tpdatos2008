package processor.words;

import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

import dto.WordDto;

public class WordsProcessor {
	
	public void processDocument(String document/*,List<WordDto> stopwords*/) throws IOException {

		List<WordDto> stopwords = prepareStopwords();
		document = deleteSpecialCharacters(document);
		document = applyCaseFolding(document);
		processPipelinedStopwords(document,stopwords);
		
	}
	
	private void processPipelinedStopwords(String document,
			List<WordDto> stopwords) {
		StringTokenizer strTok = new StringTokenizer(document," ");
		while (strTok.hasMoreTokens()) {
			String token = strTok.nextToken();
			token = stemWord(token);
//			BPlusTreeFacade.storeWord(token);
		}
	}

	private String stemWord(String token) {
		// TODO Auto-generated method stub
		return null;
	}

	private String applyCaseFolding(String document) {
		return document.toLowerCase();
	}

	private String deleteSpecialCharacters(String document) {
		return document.replaceAll("|°¬!\"#$%&/()=?'\\¿¡´¨+-*~{}[]^`,;.:_", " ");
	}

	@SuppressWarnings("deprecation")
	public static List<WordDto> prepareStopwords() throws IOException {
		List<WordDto> stopwordsList = new ArrayList<WordDto>();
		
	    File file = new File("C:\\Documents and Settings\\Nico\\Escritorio\\Organizacion de Datos\\tpdatos\\src\\utils\\stopwords\\stopwords.txt");
	    FileInputStream fis = null;
	    BufferedInputStream bis = null;
	    DataInputStream dis = null;

	    try {
	    	fis = new FileInputStream(file);

			bis = new BufferedInputStream(fis);
			dis = new DataInputStream(bis);

			while (dis.available() != 0) {
				String rawStopword = dis.readLine();
				List<String> stopword = new ArrayList<String>(); 
				String[] dividedStopWord = rawStopword.split(" ");
				for (int i=0;i<dividedStopWord.length;i++) {
					stopword.add(dividedStopWord[i]);
				}
				WordDto wDto = new WordDto(stopword);
				stopwordsList.add(wDto);
			}

			fis.close();
			bis.close();
			dis.close();

		} catch (FileNotFoundException e) {
		  e.printStackTrace();
		} catch (IOException e) {
		  e.printStackTrace();
		}		
		
	    return stopwordsList;
	}
	
	public static void main(String[] args) throws IOException {
		List<WordDto> sw = prepareStopwords();
		Collections.sort(sw);
		String last = "";
		StringBuffer sb = null;
		for (WordDto wDto : sw) {
			sb = new StringBuffer();
			sb.append(wDto.toString()+" ");
			if (!last.equals(sb.toString().trim().toLowerCase())) {
				System.out.println(sb.toString().trim().toLowerCase());
			}
			last = sb.toString().trim().toLowerCase();
		}
	}

}
