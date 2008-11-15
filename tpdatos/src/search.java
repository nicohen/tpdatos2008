import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import processor.utils.HtmlUtils;
import utils.Constants;

/**
 * Servlet implementation class search
 */

public class search extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public search() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		PrintWriter out = response.getWriter();
		out.println("<html>");
		out.println("<head>");
		out.println(doHtmlHeader(request,response));
		out.println("</head>");
		out.println("<body>");
		try {
			out.println(doHtmlBody(request,response));
		} catch (Exception e) {
		}
		out.println(doHtmlFooter(request,response));
		out.println("</body>");
		out.println("</html>");
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		super.doPost(request, response);
	}

	protected String doHtmlBody(HttpServletRequest request,HttpServletResponse response) throws Exception {
		File searchFile = new File(Constants.FILE_SEARCH_CONTENT);
		String html = HtmlUtils.readHtmlFile(searchFile.getPath());
		return html.replace("##SEARCH_WORD##", "");
	}

	protected String doHtmlFooter(HttpServletRequest request,HttpServletResponse response) {
		return "";
	}

	protected String doHtmlHeader(HttpServletRequest request,HttpServletResponse response) {
		return "";
	}

}
