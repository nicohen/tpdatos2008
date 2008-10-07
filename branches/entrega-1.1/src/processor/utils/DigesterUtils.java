package processor.utils;

import java.io.File;

import org.htmlparser.util.ParserException;

public final class DigesterUtils {
	
	private static final String LETTERS_TO_STRIP = "\"_,:.#()¿?/\\!¡$%&*'@={}[];|®´ ";
	private static final String LETTERS_TO_TRANSLATE_FROM	= "\u00E1\u00E0\u00E9\u00E8\u00ED\u00EC\u00F3\u00F2\u00FA\u00F9\u00FC";
	private static final String LETTERS_TO_TRANSLATE_TO	= "aaeeiioouuu";
	
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

			if (append){
				out.append(word[i]);
			} else {
				out.append(" ");
			}

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


	public static String getFormattedHtmlFile(File file) throws ParserException {
		String documentText = HtmlUtils.formatHtmlFile(file);
		return DigesterUtils.formatText(documentText);
	}

	public static String formatText(String documentText) {
		documentText = DigesterUtils.applyCaseFolding(documentText);
		documentText = DigesterUtils.updateAcuteAndUmlaut(documentText);
		return 		   DigesterUtils.deleteSpecialCharacters(documentText);

	}

}
