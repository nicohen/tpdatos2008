import java.io.File;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import utils.Constants;
import web.indexer.IndexerModel;
import web.indexer.IndexerStatsView;
import web.indexer.IndexerView;
import exceptions.BusinessException;


public class index extends Servlet {

	private static final long serialVersionUID = 1L;

	@Override
	protected String getHtml(HttpServletRequest request,
			HttpServletResponse response)
			throws BusinessException {
		String action= request.getParameter("action");
		if ((action!=null)&&action.equals("index")){
			String method= request.getParameter("method");
			String size= request.getParameter("size");
			IndexerModel model= new IndexerModel(getServletContext().getRealPath(File.separator),method,size);
			IndexerStatsView view= new IndexerStatsView(model);
			return view.doContent(getServletContext().getRealPath(File.separator),Constants.INDEX);
		}else{
			IndexerView view= new IndexerView();
			return view.doContent(getServletContext().getRealPath(File.separator),Constants.INDEX);
		}
	}
}
