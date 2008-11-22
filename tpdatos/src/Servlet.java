

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import exceptions.BusinessException;

import processor.utils.HtmlUtils;
import utils.Constants;

/**
 * Servlet implementation class ControllerServlet
 */

public abstract class Servlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public Servlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		ServletContext context = getServletContext();

		PrintWriter out = response.getWriter();
		try {
			out.println("<html>");
			out.println("<head>");
			out.println(doHtmlHeader(request,response,context));
			out.println("</head>");
			out.println("<body>");
			out.println(doHtmlBody(request,response,context));
			out.println(doHtmlFooter(request,response,context));
			out.println("</body>");
			out.println("</html>");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		super.doPost(request, response);
	}

	protected String doHtmlBody(HttpServletRequest request,HttpServletResponse response, ServletContext context) throws BusinessException {
		return "";
	}

	protected String doHtmlFooter(HttpServletRequest request,HttpServletResponse response, ServletContext context) throws BusinessException {
		return "";
	}

	protected String doHtmlHeader(HttpServletRequest request,HttpServletResponse response, ServletContext context) throws BusinessException {
		File javascriptFile = new File(context.getRealPath(Constants.FILE_JAVASCRIPT));
		try {
			return HtmlUtils.readHtmlFile(javascriptFile.getPath());
		} catch(IOException e) {
			throw new BusinessException("Error armando el header del HTML al leer "+Constants.FILE_JAVASCRIPT);
		}
	}

}