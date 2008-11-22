import java.io.File;
import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import exceptions.DataAccessException;
import exceptions.PersistanceException;

import app.po.files.RelativeFile;
import app.po.persistors.IntegerPersistor;


public class Indexer extends HttpServlet {

	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		this.doGet(request, response);
	}
	
	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String method= request.getParameter("method");
		String size= request.getParameter("size");
		IndexerModel model= new IndexerModel(getServletContext().getRealPath(File.separator),method,size);
		IndexerView view= new IndexerView(model);
		view.doOutput(request,response);
	}
}
