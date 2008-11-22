import java.io.File;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import web.indexer.IndexerModel;
import web.indexer.IndexerView;
import exceptions.BusinessException;


public class index extends Servlet {

	private static final long serialVersionUID = 1L;

	@Override
	protected String getHtml(HttpServletRequest request,
			HttpServletResponse response)
			throws BusinessException {
		String method= request.getParameter("method");
		String size= request.getParameter("size");
		IndexerModel model= new IndexerModel(getServletContext().getRealPath(File.separator),method,size);
		IndexerView view= new IndexerView(model);
		return view.doContent(getServletContext().getRealPath(File.separator));
	}
}
