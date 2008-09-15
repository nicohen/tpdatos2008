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

import dto.DocumentDto;
import dto.LineDto;
import dto.WordDto;

public class PipelinedWordsProcessor {
	
	public void processDocument(DocumentDto document) throws IOException {

//		DocumentDto correctedDocument = new DocumentDto();
//		correctedDocument.setDocument(document.getDocument());
	
		List<LineDto> stopwords = prepareStopwords();
		
//		for (LineDto pipelineDto : document.getPipelines()) {
//			for (AbstractWordsProcessor processor : WordsProcessorPipelineFactory.getPipeline()) {
//				correctedDocument.addPipeline(processor.process(pipelineDto));
//			}
//		}
		
//		System.out.println(correctedDocument.toString());
		
	}
	
	@SuppressWarnings("deprecation")
	public static List<LineDto> prepareStopwords() throws IOException {
		List<LineDto> pipelinesList = new ArrayList<LineDto>();
		
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
				LineDto pDto = new LineDto(rawStopword);
				String[] dividedStopWord = rawStopword.split(" ");
				for (int i=0;i<dividedStopWord.length;i++) {
					pDto.addWord(new WordDto(dividedStopWord[i]));
				}
				pipelinesList.add(pDto);
			}

			fis.close();
			bis.close();
			dis.close();

		} catch (FileNotFoundException e) {
		  e.printStackTrace();
		} catch (IOException e) {
		  e.printStackTrace();
		}		
		
	    return pipelinesList;
	}
	
	public static void main(String[] args) throws IOException {
		List<LineDto> sw = prepareStopwords();
		Collections.sort(sw);
		String last = "";
		StringBuffer sb = null;
		for (LineDto pDto : sw) {
			sb = new StringBuffer();
			for (WordDto wDto : pDto.getWordsPipeline()) {
				sb.append(wDto.toString()+" ");
			}
			if (!last.equals(sb.toString().trim().toLowerCase())) {
				System.out.println(sb.toString().trim().toLowerCase());
			}
			last = sb.toString().trim().toLowerCase();
		}
	}

}
