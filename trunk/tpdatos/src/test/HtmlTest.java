package test;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

import org.htmlparser.util.ParserException;

import processor.web.utils.HtmlUtils;



public class HtmlTest {

	public static void main(String[] args) throws ParserException, IOException {
		
		
		File file = new File("userdoc/river.txt");
		InputStream fis = new FileInputStream(file);
		int letra;
		String html = "";
		letra = fis.read();
		while (letra!=-1) {
			html+=(char)letra;
			letra = fis.read();
		}
		
		String body = "";
		//Obtengo el body del HTML
		// FIXME - No esta filtrando del todo correctamente los tags <script>
		body = HtmlUtils.getHtmlBody(html);
		//Elimina todos los tags HTML
		body = HtmlUtils.trimAllTags(body);
		//Decodifica los caracteres especiales de HTML
		body = HtmlUtils.decodeSpecialCharacters(body);
		
		
		System.out.println(body);
	}
}
