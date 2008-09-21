package processor.web.utils;

import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

import app.po.files.RelativeFile;
import app.po.persistors.AbstractPersistor;
import app.po.persistors.DocumentPersistor;
import dto.DocumentDto;
import dto.WordDto;
import exceptions.BusinessException;
import exceptions.DataAccessException;

public final class DigesterUtils {
	
	public static List<DocumentDto> prepareNewDocuments() {
		List<DocumentDto> documentsList = new ArrayList<DocumentDto>();
		return documentsList;
	}
	
	public static Map<Integer,String> prepareIndexedDocuments() throws BusinessException {
		Map<Integer,String> documentsMap = new TreeMap<Integer,String>();
		AbstractPersistor<DocumentDto> persistor = new DocumentPersistor(10);
		try {
			RelativeFile<DocumentDto> relativeFile = new RelativeFile<DocumentDto>("indexed_documents.bin",persistor);
			DocumentDto document = null;
			int docId = 0;
			while((document=relativeFile.get(docId++))!=null) {
				documentsMap.put(document.getDocumentId(), document.getFileName());
			}

			return documentsMap;
		} catch (DataAccessException e) {
			throw new BusinessException("Error inicializando RelativeFile de documentos indexados",e);
		}
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

}
