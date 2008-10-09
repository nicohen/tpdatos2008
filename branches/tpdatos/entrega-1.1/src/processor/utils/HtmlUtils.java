package processor.utils;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

import org.htmlparser.Node;
import org.htmlparser.NodeFilter;
import org.htmlparser.Parser;
import org.htmlparser.filters.AndFilter;
import org.htmlparser.filters.NodeClassFilter;
import org.htmlparser.filters.NotFilter;
import org.htmlparser.nodes.TagNode;
import org.htmlparser.nodes.TextNode;
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
			nuevo = getNodeText(node);
		}

		return nuevo;
	}
	
	public static String deleteTags(String html) {
		return html.replaceAll("<(.|\n)*?>", "#");
	}
	
	public static String decodeSpecialHtmlCharacters(String html) {
		return Translate.decode(html);
	}
	
	public static String readHtmlFile(String fileName) {
	    File file = new File(fileName);
	    StringBuilder html = new StringBuilder();
	    FileReader fr = null;
	    BufferedReader br = null;

	    try {
	    	fr = new FileReader(file);

	      // Here BufferedInputStream is added for fast reading.
	    	br = new BufferedReader(fr);

			
			int letra= br.read();
			while (letra>-1){
				html.append((char)letra);
				letra= br.read();
			}
	      // dispose all the resources after using them.
	      br.close();
	      fr.close();

	    } catch (FileNotFoundException e) {
	      e.printStackTrace();
	    } catch (IOException e) {
	      e.printStackTrace();
	    }
	    return html.toString();
	}

	public static String formatHtmlFile(File file) throws ParserException {
		String documentText = HtmlUtils.readHtmlFile(file.getPath());
		documentText = HtmlUtils.getHtmlBody(documentText);
		documentText = HtmlUtils.deleteTags(documentText);
		return HtmlUtils.decodeSpecialHtmlCharacters(documentText);
	}
	
	private static String getNodeText(Node node) throws ParserException {
		StringBuilder sb = new StringBuilder();
		if(!node.getClass().equals(ScriptTag.class)) {
			if (node.getClass().equals(TextNode.class)) {
				sb.append(node.getText());
			} else {
				if (node.getChildren()!=null) {
					NodeIterator it = node.getChildren().elements();
					while (it.hasMoreNodes()){
						sb.append(getNodeText(it.nextNode()));
					}
				}
			}
		}
		return sb.toString();
		
	}
}
