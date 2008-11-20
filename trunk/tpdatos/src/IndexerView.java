import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import utils.Constants;
import utils.statistics.Statistics;


public class IndexerView {

	IndexerModel model;
	
	public IndexerView(IndexerModel model) {
		this.model= model;
	}

	public void doOutput(HttpServletRequest request,
			HttpServletResponse response) {	
		try {
			Statistics stats= model.indexPath(Constants.FOLDER_DOCUMENTS);
			ServletOutputStream	out= response.getOutputStream();
			out.print(stats.toString());
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
}
