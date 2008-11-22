package web;

import java.io.File;
import java.io.IOException;

import processor.utils.HtmlUtils;
import utils.Constants;

public abstract class View {

	public String doContent(String basePath) {
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
		strBuf.append(doHtmlHeader());
		strBuf.append("</head>");
		strBuf.append("<body>");
		strBuf.append(html.replace("##CONTENT##", doHtmlBody()));
		strBuf.append(doHtmlFooter());
		strBuf.append("</body>");
		strBuf.append("</html>");
		
		return strBuf.toString();

	}

	protected String doHtmlFooter() {return "";}
	protected abstract String doHtmlBody();
	protected String doHtmlHeader() {return "";}
}
