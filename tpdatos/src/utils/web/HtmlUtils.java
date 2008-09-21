package utils.web;

import org.htmlparser.NodeFilter;
import org.htmlparser.Parser;
import org.htmlparser.filters.AndFilter;
import org.htmlparser.filters.NodeClassFilter;
import org.htmlparser.filters.NotFilter;
import org.htmlparser.nodes.TagNode;
import org.htmlparser.tags.BodyTag;
import org.htmlparser.tags.ScriptTag;
import org.htmlparser.util.NodeIterator;
import org.htmlparser.util.NodeList;
import org.htmlparser.util.ParserException;
import org.htmlparser.util.SimpleNodeIterator;
import org.htmlparser.util.Translate;

public final class HtmlUtils {
	
	public static String getHtmlBody(String html) throws ParserException {
		Parser parser = new Parser();
		parser.setInputHTML(html);
		
		String nuevo = "";
		
		NodeList list = new NodeList();
		NodeFilter filter = new AndFilter(
				new NodeClassFilter(BodyTag.class),
				new NotFilter(new NodeClassFilter(ScriptTag.class))
			);
		for (NodeIterator e = parser.elements (); e.hasMoreNodes (); )
		    e.nextNode ().collectInto (list, filter);

		SimpleNodeIterator it = list.elements();
		
		while (it.hasMoreNodes()) {
			TagNode node = (TagNode) it.nextNode();
			nuevo = node.toHtml();
		}

		return nuevo;
	}
	
	public static String trimAllTags(String html) {
		return html.replaceAll("<(.|\n)*?>", " ");
	}
	
	public static String decodeSpecialCharacters(String html) {
		return Translate.decode(html);
	}
	
}
