package utils;

import java.io.File;

public class Constants {
	// /documents
	public static final String FOLDER_DOCUMENTS = "documents";
		// /documents/indexed
		public static final String FOLDER_INDEXED = FOLDER_DOCUMENTS+File.separator+"indexed";
	
	// /src
	public static final String FOLDER_SOURCE = "src";
		// /src/utils
		public static final String FOLDER_PROCESSOR = FOLDER_SOURCE+File.separator+"processor";
			// /src/utils/stopwords
			public static final String FOLDER_STOPWORDS = FOLDER_PROCESSOR+File.separator+"stopwords";
				// /src/utils/stopwords/stopwords.txt
				public static final String FILE_STOPWORDS = FOLDER_STOPWORDS+File.separator+"stopwords.txt";
	
				
	public static final String INDEX_FILE_PATH = "index.bin";
	public static final int    INDEX_FILE_SIZE = 4096;

	public static final String BPLUS_FILE_PATH = "bplus.dat";
	public static final int    BPLUS_FILE_SIZE = 128;
	
	public static final String BPLUS_TEST_FILE_PATH = "bplus-test.dat";
}
