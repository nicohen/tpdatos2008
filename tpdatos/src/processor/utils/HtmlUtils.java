package processor.utils;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

import org.htmlparser.Node;
import org.htmlparser.NodeFilter;
import org.htmlparser.Parser;
import org.htmlparser.filters.NodeClassFilter;
import org.htmlparser.nodes.TagNode;
import org.htmlparser.nodes.TextNode;
import org.htmlparser.tags.BodyTag;
import org.htmlparser.tags.ScriptTag;
import org.htmlparser.tags.StyleTag;
import org.htmlparser.util.NodeIterator;
import org.htmlparser.util.NodeList;
import org.htmlparser.util.ParserException;
import org.htmlparser.util.SimpleNodeIterator;
import org.htmlparser.util.Translate;

public final class HtmlUtils {
	
	public static String getHtmlBody(String html) throws ParserException {
		Parser parser = new Parser();
		parser.setInputHTML(html);
		
		NodeList list = new NodeList();
		NodeFilter filter = new NodeClassFilter(BodyTag.class);
		for (NodeIterator e = parser.elements (); e.hasMoreNodes (); )
		    e.nextNode ().collectInto (list, filter);

		SimpleNodeIterator it = list.elements();
		
		StringBuffer strBuf = new StringBuffer();
		while (it.hasMoreNodes()) {
			TagNode node = (TagNode) it.nextNode();
			strBuf.append(getNodeText(node)).append('\n');
		}

		return strBuf.toString();
	}
	
	public static String decodeSpecialHtmlCharacters(String html) {
		return Translate.decode(html);
	}
	
	public static String readHtmlFile(String fileName) throws IOException {
	    File file = new File(fileName);
	    StringBuilder html = new StringBuilder();
	    FileReader fr = null;
	    BufferedReader br = null;

	    try {
	    	fr = new FileReader(file);
	    } catch(FileNotFoundException e) {
	    	throw new IOException("El archivo "+file.getAbsolutePath()+" no se ha encontrado");
	    }

    	br = new BufferedReader(fr);

    	int letra= br.read();
		while (letra>-1){
			html.append((char)letra);
			letra= br.read();
		}
        br.close();
	    fr.close();

	    return html.toString();
	}

	public static String formatHtmlFile(File file) throws ParserException {
		String documentText = "";
		try {
			documentText = HtmlUtils.readHtmlFile(file.getPath());
		} catch(IOException e) {
			throw new ParserException("Error obteniendo html del archivo "+file.getPath(),e);
		}
		//Elimino scripts javascript
		documentText = documentText.replaceAll("<script[^>]*?>[\\s\\S]*?<\\/script>", "\n");
		//Obtengo el body con los tags trimeeados
		documentText = HtmlUtils.getHtmlBody(documentText);
		//Decodifico caracteres especiales de html
		return HtmlUtils.decodeSpecialHtmlCharacters(documentText);
	}
	
	private static String getNodeText(Node node) throws ParserException {
		StringBuilder sb = new StringBuilder();
		if(!node.getClass().equals(ScriptTag.class) && !node.getClass().equals(StyleTag.class)) {
			if (node.getClass().equals(TextNode.class)) {
				sb.append(node.getText()).append('\n');
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
