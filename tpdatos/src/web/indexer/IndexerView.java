package web.indexer;

import java.io.File;
import java.io.IOException;

import processor.utils.HtmlUtils;
import web.View;

public class IndexerView extends View {

	@Override
	protected String doHtmlBody(String basePath) {
		try {
			File documentsResultRowFile = new File(basePath+"/html/index_form.html");
			String indexContentHtml = HtmlUtils.readHtmlFile(documentsResultRowFile.getPath());
			return indexContentHtml;
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return "ERROR!!!";
	}
	
	@Override
	protected String doHtmlHeader(String basePath) {
		StringBuffer sb= new StringBuffer();
		sb.append(super.doHtmlHeader(basePath));
		File file = new File(basePath+"/html/index_script.html");
		try {
			sb.append(HtmlUtils.readHtmlFile(file.getPath()));
		} catch(IOException e) {
			e.printStackTrace();
		}
		return sb.toString();
	}

}
