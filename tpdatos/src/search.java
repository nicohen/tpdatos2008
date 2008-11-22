import java.io.File;
import java.io.IOException;

import javax.servlet.ServletContext;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import processor.utils.HtmlUtils;
import utils.Constants;
import exceptions.BusinessException;

/**
 * Servlet implementation class search
 */

public class search extends Servlet {
	private static final long serialVersionUID = 1L;
       
    public search() { super(); }

	protected String doHtmlBody(HttpServletRequest request,HttpServletResponse response, ServletContext context) throws BusinessException {
		File searchFile = new File(context.getRealPath(Constants.FILE_SEARCH_CONTENT));
		try {
			String html = HtmlUtils.readHtmlFile(searchFile.getPath());
			return html.replace("##SEARCH_WORD##", "");
		} catch(IOException e) {
			throw new BusinessException("",e);
		}
	}

	protected String doHtmlFooter(HttpServletRequest request,HttpServletResponse response) {
		return "";
	}

	protected String doHtmlHeader(HttpServletRequest request,HttpServletResponse response) {
		return "";
	}

}
