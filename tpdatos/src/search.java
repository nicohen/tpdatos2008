import java.io.File;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import utils.Constants;
import web.search.SearchModel;
import web.search.SearchView;
import exceptions.BusinessException;

/**
 * Servlet implementation class search
 */

public class search extends Servlet {
	private static final long serialVersionUID = 1L;
    
	@Override
	protected String getHtml(HttpServletRequest request,HttpServletResponse response) throws BusinessException {
		String searchWord = request.getParameter("as_word");
		SearchModel model= new SearchModel(searchWord);
		SearchView view= new SearchView(model);
		return view.doContent(getServletContext().getRealPath(File.separator),Constants.SEARCH);
	}
}