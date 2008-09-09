import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;

import org.htmlparser.util.ParserException;

import processor.web.utils.HtmlUtils;



public class HtmlTest {

	public static void main(String[] args) throws ParserException, IOException {
		
		
		File file = new File("userdoc/teclados.txt");
		InputStream fis = new FileInputStream(file);
		char letra;
		byte[] bytes = null;
		int offset = 0;
		String html = "";
		while ((letra = (char)fis.read(bytes,offset,50)) !=-1) {
			html+=letra;
		}
		
		String body = HtmlUtils.getHtmlBody(html);
		System.out.println(body);
	}
}
