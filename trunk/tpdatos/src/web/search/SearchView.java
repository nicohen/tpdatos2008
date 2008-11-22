package web.search;

import java.io.File;
import java.io.IOException;

import processor.utils.HtmlUtils;
import utils.Constants;
import web.View;


public class SearchView extends View {

	SearchModel model;
	
	public SearchView(SearchModel model) {
		this.model = (SearchModel)model;
	}
	
	@Override
	protected String doHtmlBody(String basePath) {
		File file = new File(basePath+Constants.FILE_SEARCH_CONTENT);

		String html = "";
		try {
			html = HtmlUtils.readHtmlFile(file.getPath());
			if(!"".equals(model.getSearchWord())) {
				html = html.replace("##SEARCH_WORD##", model.getSearchWord());
			} else {
				html = html.replace("##SEARCH_WORD##", "");
			}
		} catch(IOException e) {
			e.printStackTrace();
		}

		return html;
	}


}
