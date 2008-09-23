package utils.processor;

import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileFilter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

import utils.folders.Constants;
import dto.WordDto;
import exceptions.BusinessException;

public final class DigesterUtils {
	
	public static final String LETTERS_TO_STRIP = "\"_,:.#()?¿/\\!$%&*'@ºª=¡{}[];";
	public static final String LETTERS_TO_TRANSLATE_FROM	= "\u00E1\u00E0\u00E9\u00E8\u00ED\u00EC\u00F3\u00F2\u00FA\u00F9\u00FC";
	public static final String LETTERS_TO_TRANSLATE_TO	= "aaeeiioouuu";
	
	public static File[] prepareNewDocuments(String documentsPath) {
	    File dir = new File(documentsPath);
	    
	    String[] children = dir.list();
	    if (children == null) {
	    	System.out.println("Directorio inexistente ["+dir.getPath()+"]");
	    }
	    
	    // The list of files can also be retrieved as File objects
	    File[] files = dir.listFiles();
	    
	    // This filter only returns directories
	    FileFilter fileFilter = new FileFilter() {
	        public boolean accept(File file) {
	            return file.isFile();
	        }
	    };
	    files = dir.listFiles(fileFilter);


		return files;
	}
	
	public static Map<Integer,String> prepareIndexedDocuments() throws BusinessException {
		Map<Integer,String> documentsMap = new TreeMap<Integer,String>();
//		AbstractPersistor<DocumentDto> persistor = new DocumentPersistor(10);
//		try {
//			RelativeFile<DocumentDto> relativeFile = new RelativeFile<DocumentDto>("indexed_documents.bin",persistor);
//			DocumentDto document = null;
//			int docId = 0;
//			while((document=relativeFile.get(docId++))!=null) {
//				documentsMap.put(document.getDocumentId(), document.getFileName());
//			}
//
//			return documentsMap;
//		} catch (DataAccessException e) {
//			throw new BusinessException("Error inicializando RelativeFile de documentos indexados",e);
//		}
		return documentsMap;
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

	public static String stemWord(String token) {
//		===== FORMAS NO PERSONALES =====
//			==== Infinitivo ====
//			-ar/-er/-ir
//			===== INDICATIVO =====
//			==== Presente ====
//			-o:-/
//			-as:-
//			-es:-/
//			-a:-//-e:-/
//			-amos/-emos/-imos
//			-áis/-éis/-ís
//			-an/-en
//			==== Pretérito imperfecto ====
//			-aba/-ía
//			-abas/-ías
//			-aba/-ía
//			-ábamos/-íamos
//			-abais/-íais
//			-aban/-ían
//			==== Pretérito perfecto ====
//			-é:-//-í
//			-aste/-iste
//			-ó:-//-ió
//			-amos/-imos
//			-asteis/-isteis
//			-aron/-ieron
//			==== Futuro ====
//			-aré/-eré/-iré
//			-arás/-erás/-irás
//			-ará/-erá/-irá
//			-aremos/-eremos/-iremos
//			-aréis/-eréis/-iréis
//			-arán/-erán/-irán
//			==== Condicional ====
//			-aría/-ería/-iría
//			-arías/-erías/-irías
//			-aría/-ería/-iría
//			-aríamos/-eríamos/-iríamos
//			-aríais/-eríais/-iríais
//			-arían/-erían/-irían
//			===== SUBJUNTIVO =====
//			==== Presente ====
//			-e:-//-a:-/
//			-es:-//-as:-/
//			-e:-//-a:-/
//			-emos/-amos
//			-éis/-áis
//			-en/-an
//			==== Pretérito imperfecto ====
//			-ara/-ase/-iera/-iese
//			-aras/-ases/-ieras/-ieses
//			-ara/-ase/-iera/-iese
//			-áramos/-ásemos/-iéramos/-iésemos
//			-arais/-aseis/-ierais/-ieseis
//			-aran/-asen/-ieran/-iesen
//			==== Futuro ====
//			-are/-iere
//			-ares/-ieres
//			-are/-iere
//			-áremos/-iéremos
//			-areis/-iereis
//			-aren/-ieren
//			===== IMPERATIVO =====
//			-a:-
//			-e:-/
//			-á:-//-e:-//-í
//			-ad/-ed/-id
//			-en/-an
		return token;
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

	public static void moveFileToIndexed(File file) {
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
	
	
	public static String stripLetters(String origWord, String toEliminate) {

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


	public static String translate(String origWord, String pFrom, String pTo){

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


}
