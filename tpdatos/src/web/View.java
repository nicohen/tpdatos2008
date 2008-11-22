package web;

import java.io.File;
import java.io.IOException;

import processor.utils.HtmlUtils;
import utils.Constants;

public abstract class View {

	public String doContent(String basePath, String mode) {
		File file = new File(basePath+Constants.FILE_DEFAULT_CONTENT);

		String html = "";
		try {
			html = HtmlUtils.readHtmlFile(file.getPath());
		} catch(IOException e) {
			e.printStackTrace();
		}

		StringBuffer strBuf = new StringBuffer();
		
		strBuf.append("<html>");
		strBuf.append("<head>");
		strBuf.append(doHtmlHeader(basePath));
		strBuf.append("</head>");
		strBuf.append("<body>");
		html = html.replace("##CONTENT##", doHtmlBody(basePath));
		if(mode.equals(Constants.INDEX)) {
			html = html.replace("##BUSCAR##", "<a href='search'>Buscar</a>");
			html = html.replace("##INDEXAR##", "<b>Indexar</b>");
		} else if (mode.equals(Constants.SEARCH)) {
			html = html.replace("##BUSCAR##", "<b>Buscar</b>");
			html = html.replace("##INDEXAR##", "<a href='index'>Indexar</a>");
		} else {
			html = html.replace("##BUSCAR##", "<a href='search'>Buscar</a>");
			html = html.replace("##INDEXAR##", "<a href='index'>Indexar</a>");
		}
		strBuf.append(html);
		strBuf.append(doHtmlFooter(basePath));
		strBuf.append("</body>");
		strBuf.append("</html>");
		
		return strBuf.toString();

	}

	protected String doHtmlFooter(String basePath) {
		return "";
	}
	
	protected abstract String doHtmlBody(String basePath);
	
	protected String doHtmlHeader(String basePath) {
		File file = new File(basePath+Constants.FILE_JAVASCRIPT);

		String html = "";
		try {
			html = HtmlUtils.readHtmlFile(file.getPath());
		} catch(IOException e) {
			e.printStackTrace();
		}

		return html;
	
	}
}
