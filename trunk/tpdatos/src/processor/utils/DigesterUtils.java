package processor.utils;

import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileFilter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import org.htmlparser.util.ParserException;

import processor.IndexedDocumentChecker;
import utils.Constants;
import dto.WordDto;
import exceptions.BusinessException;

public final class DigesterUtils {
	
	private static final String LETTERS_TO_STRIP = "\"_,:.#()¿?/\\!¡$%&*'@={}[];|®";
	private static final String LETTERS_TO_TRANSLATE_FROM	= "\u00E1\u00E0\u00E9\u00E8\u00ED\u00EC\u00F3\u00F2\u00FA\u00F9\u00FC";
	private static final String LETTERS_TO_TRANSLATE_TO	= "aaeeiioouuu";
	
	public static File[] prepareNewDocuments(String documentsPath) {
	    File dir = new File(documentsPath);
	    
	    String[] children = dir.list();
	    if (children == null) {
	    	System.out.println("Directorio inexistente ["+dir.getPath()+"]");
	    }
	    
	    // Este filtro solamente retorna archivos
	    FileFilter fileFilter = new FileFilter() {
	        public boolean accept(File file) {
	            return file.isFile();
	        }
	    };
	    
	    return dir.listFiles(fileFilter);
	}
	
	public static IndexedDocumentChecker prepareIndexedDocuments() throws BusinessException {
		
		IndexedDocumentChecker checker = new IndexedDocumentChecker();
		
//		AbstractPersistor<DocumentDto> persistor = new DocumentPersistor(10);
//		try {
//			RelativeFile<DocumentDto> relativeFile = new RelativeFile<DocumentDto>("indexed_documents.bin",persistor);
//			DocumentDto document = null;
//			int docId = 0;
//			while((document=relativeFile.get(docId++))!=null) {
//				checker.addDocument(document.getDocumentId(), document.getFileName());
//			}
//
//		} catch (DataAccessException e) {
//			throw new BusinessException("Error inicializando RelativeFile de documentos indexados",e);
//		}
		return checker;
	}
	
	@SuppressWarnings("deprecation")
	public static List<WordDto> prepareStopwords() throws IOException {
		List<WordDto> stopwordsList = new ArrayList<WordDto>();
		
	    File file = new File(Constants.FILE_STOPWORDS);
	    FileInputStream fis = null;
	    BufferedInputStream bis = null;
	    DataInputStream dis = null;

	    try {
	    	fis = new FileInputStream(file);
			bis = new BufferedInputStream(fis);
			dis = new DataInputStream(bis);
			
			String stopword = null;
			
			while (dis.available() != 0) {
				String rawStopword = dis.readLine();
				List<String> words = new ArrayList<String>(); 
				String[] dividedStopWord = rawStopword.split(" ");
				for (int i=0;i<dividedStopWord.length;i++) {
					stopword = dividedStopWord[i];
					stopword = updateAcuteAndUmlaut(stopword);
					stopword = deleteSpecialCharacters(stopword);
					words.add(stopword);
				}
				WordDto wDto = new WordDto(words);
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

	public static String updateAcuteAndUmlaut(String document) {
		return replaceUTFCharacters(document);
	}

	public static String deleteSpecialCharacters(String document) {
		return stripLetters(document, LETTERS_TO_STRIP);
	}

	private static String replaceUTFCharacters(String document) {
		return translate(document, LETTERS_TO_TRANSLATE_FROM, LETTERS_TO_TRANSLATE_TO);
	}

	public static String applyCaseFolding(String document) {
		return document.toLowerCase();
	}
	
	public static void moveFileToIndexedFolder(File file) {
	    // Destination directory
	    File dir = new File(Constants.FOLDER_INDEXED);
	    
	    // Move file to new directory
	    boolean success = file.renameTo(new File(dir, file.getName()));
	    if (!success) {
	    	System.out.println("Error moviendo ["+file.getName()+"] a la carpeta de indexados");
	    } else {
	    	System.out.println("Se ha movido el archivo ["+file.getName()+"] a la carpeta de indexados");
	    }

	}
	
	
	private static String stripLetters(String origWord, String toEliminate) {

		int i,j;
		char[] word  = origWord.toCharArray();
		char[] chars = toEliminate.toCharArray();
		boolean append;
		StringBuffer out = new StringBuffer();

		for (i=0; i<word.length; i++){

			append = true;
			for (j=0; j<chars.length; j++){
				if ( word[i] == chars[j] ){
					append = false;
					break;
				}
			}

			if (append)
				out.append(word[i]);

		}
		return out.toString();
	}


	private static String translate(String origWord, String pFrom, String pTo){

		int i,j;
		char[] word		= origWord.toCharArray();
		char[] from		= pFrom.toCharArray();
		char[] to		= pTo.toCharArray();
		boolean found;
		StringBuffer out = new StringBuffer();

		for (i=0; i<word.length; i++){

			found = false;
			for (j=0; j < to.length; j++){
				if ( word[i] == from[j] ){
					out.append(to[j]);
					found = true;
					break;
				}
			}

			if ( !found )
				out.append(word[i]);

		}
		return out.toString();
	}


	public static String getFormatedHtmlFile(File file) throws ParserException {
		String documentText = HtmlUtils.formatHtmlFile(file);
		return DigesterUtils.formatText(documentText);
	}

	public static String formatText(String documentText) {
		documentText = DigesterUtils.applyCaseFolding(documentText);
		documentText = DigesterUtils.updateAcuteAndUmlaut(documentText);
		return 		   DigesterUtils.deleteSpecialCharacters(documentText);

	}

}
