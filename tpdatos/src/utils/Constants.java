package utils;

import java.io.File;

public class Constants {
	// /documents
	public static final String FOLDER_DOCUMENTS = "documents";
		// /documents/indexed
		public static final String FOLDER_INDEXED = FOLDER_DOCUMENTS+File.separator+"indexed";
	
	//Indexed documents por signature files
	public static final String FILE_SIGNATURE_FILES_INDEXED_DOCS = "indexed_signature_documents.bin";
	public static final String FILE_INDICE_INVERTIDO_INDEXED_DOCS = "indexed_indinvertido_documents.bin";
		
	// /words
	public static final String FOLDER_WORDS = "words";
		// /words/stopwords.txt
		public static final String FILE_STOPWORDS = FOLDER_WORDS+File.separator+"stopwords.txt";
		// /words/stemming.txt
		public static final String FILE_STEMMING = FOLDER_WORDS+File.separator+"stemming.txt";

	// /html
	public static final String FOLDER_HTML = "html";
		// /html/search.html
		public static final String FILE_SEARCH_CONTENT = File.separator+FOLDER_HTML+File.separator+"search.html";
		// /html/javascript.html
		public static final String FILE_JAVASCRIPT = File.separator+FOLDER_HTML+File.separator+"javascript.html";
				
	public static final String INDEX_FILE_PATH = "index.bin";
	public static final int    INDEX_FILE_SIZE = 512;

	public static final String BPLUS_FILE_PATH = "bplus.dat";
	public static final int    BPLUS_FILE_SIZE = 4096;
	
	public static final String SIGNATURE_FILE_PATH = "signatures.dat";
	public static final int    SIGNATURE_FILE_SIZE = 4096;
	public static final int    SIGNATURE_SIZE = 11;
	
	public static final String BPLUS_TEST_FILE_PATH = "bplus-test.dat";
}
