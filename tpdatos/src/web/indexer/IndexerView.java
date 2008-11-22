package web.indexer;
import utils.Constants;
import utils.statistics.Statistics;
import web.View;


public class IndexerView extends View {

	IndexerModel model;
	
	public IndexerView(IndexerModel model) {
		this.model= model;
	}

	@Override
	protected String doHtmlBody() {
		try {
			Statistics stats= model.indexPath(Constants.FOLDER_DOCUMENTS);
			return stats.toString();
		} catch (Exception e) {
			e.printStackTrace();
		}
		return "Ocurrio un Error";
	}
	
}
