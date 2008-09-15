package processor.words.machine;

import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;
import java.util.ArrayList;
import java.util.List;

import processor.words.AbstractWordsProcessor;
import dto.WordDto;

public class AccentUmlautCorrectorWordsProcessor extends AbstractWordsProcessor {

	public AccentUmlautCorrectorWordsProcessor() {
		super();
	}

	public WordDto process(WordDto wordDto) {
		List<String> words = new ArrayList<String>();
		for (String word : wordDto.getWord()) {
			try {
				words.add(URLDecoder.decode(word, "UTF-8"));
			} catch (UnsupportedEncodingException e) {
				words.add(word);
			}
		}
		return new WordDto(words);
	}

}
