package utils;

import java.io.File;

public class Constants {
	// /documents
	public static final String FOLDER_DOCUMENTS = "documents";
		// /documents/indexed
		public static final String FOLDER_INDEXED = FOLDER_DOCUMENTS+File.separator+"indexed";
	
	// /words
	public static final String FOLDER_WORDS = "words";
		// /words/stopwords.txt
		public static final String FILE_STOPWORDS = FOLDER_WORDS+File.separator+"stopwords.txt";
		// /words/stemming.txt
		public static final String FILE_STEMMING = FOLDER_WORDS+File.separator+"stemming.txt";
	
				
	public static final String INDEX_FILE_PATH = "index.bin";
	public static final int    INDEX_FILE_SIZE = 512;

	public static final String BPLUS_FILE_PATH = "bplus.dat";
	public static final int    BPLUS_FILE_SIZE = 4096;
	
	public static final String SIGNATURE_FILE_PATH = "bplus.dat";
	public static final int    SIGNATURE_FILE_SIZE = 4096;
	
	public static final String BPLUS_TEST_FILE_PATH = "bplus-test.dat";
}
