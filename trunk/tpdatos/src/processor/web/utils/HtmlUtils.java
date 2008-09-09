package processor.web.utils;

import org.htmlparser.Node;
import org.htmlparser.NodeFilter;
import org.htmlparser.Parser;
import org.htmlparser.filters.TagNameFilter;
import org.htmlparser.util.NodeList;
import org.htmlparser.util.ParserException;
import org.htmlparser.util.SimpleNodeIterator;

public final class HtmlUtils {
	
	public static String getHtmlBody(String html) throws ParserException {
		Parser parser = new Parser();
		parser.setInputHTML(html);
		
		NodeFilter filter = new TagNameFilter("body");
		NodeList list = parser.parse(filter);
		SimpleNodeIterator it = list.elements();
		
		while (it.hasMoreNodes()) {
			Node node = it.nextNode();
		}

		return null;
		
	}
}
