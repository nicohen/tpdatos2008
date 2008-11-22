

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import processor.utils.HtmlUtils;
import utils.Constants;
import exceptions.BusinessException;

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
		PrintWriter out = response.getWriter();
		try {
			out.print(getHtml(request, response));
		} catch (BusinessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		super.doPost(request, response);
	}

	protected String getHtml(HttpServletRequest request,HttpServletResponse response) throws BusinessException {
		return "";
	}

	protected String doHtmlFooter(HttpServletRequest request,HttpServletResponse response) throws BusinessException {
		return "";
	}

	protected String doHtmlHeader(HttpServletRequest request,HttpServletResponse response) throws BusinessException {
		File javascriptFile = new File(getServletContext().getRealPath(Constants.FILE_JAVASCRIPT));
		try {
			return HtmlUtils.readHtmlFile(javascriptFile.getPath());
		} catch(IOException e) {
			throw new BusinessException("Error armando el header del HTML al leer "+Constants.FILE_JAVASCRIPT);
		}
	}

}