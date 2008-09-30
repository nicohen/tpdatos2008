package processor.utils;

import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

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
	
	public static String deleteTags(String html) {
		return html.replaceAll("<(.|\n)*?>", " ");
	}
	
	public static String deleteScripts(String html) {
		return html.replaceAll("<script(.|\n)*?>(.|\n)*?</script>", " ");
	}
	
	public static String decodeSpecialHtmlCharacters(String html) {
		return Translate.decode(html);
	}
	
	@SuppressWarnings("deprecation")
	public static String readHtmlFile(String fileName) {
	    File file = new File(fileName);
	    StringBuilder html = new StringBuilder();
	    FileInputStream fis = null;
	    BufferedInputStream bis = null;
	    DataInputStream dis = null;

	    try {
	      fis = new FileInputStream(file);

	      // Here BufferedInputStream is added for fast reading.
	      bis = new BufferedInputStream(fis);
	      dis = new DataInputStream(bis);

	      // dis.available() returns 0 if the file does not have more lines.
	      while (dis.available() != 0) {

	      // this statement reads the line from the file and print it to
	        // the console.
	        html.append(dis.readLine());
	        html.append("\n");
	      }

	      // dispose all the resources after using them.
	      fis.close();
	      bis.close();
	      dis.close();

	    } catch (FileNotFoundException e) {
	      e.printStackTrace();
	    } catch (IOException e) {
	      e.printStackTrace();
	    }
	    return html.toString();
	}
}
