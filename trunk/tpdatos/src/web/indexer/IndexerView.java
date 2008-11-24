package web.indexer;
import java.io.File;
import java.util.Map.Entry;

import processor.utils.HtmlUtils;
import utils.Constants;
import utils.statistics.Statistics;
import web.View;
import dto.DocumentDto;
import dto.DocumentStatisticsDto;


public class IndexerView extends View {

	IndexerModel model;
	
	public IndexerView(IndexerModel model) {
		this.model= model;
	}

	@Override
	protected String doHtmlBody(String basePath) {		
		try {
			File documentsResultRowFile = new File(basePath+"/html/index_body.html");
			String indexContentHtml = HtmlUtils.readHtmlFile(documentsResultRowFile.getPath());
			documentsResultRowFile = new File(basePath+"/html/index_doc.html");
			String indexDocumentHtml = HtmlUtils.readHtmlFile(documentsResultRowFile.getPath());
			documentsResultRowFile = new File(basePath+"/html/index_stats.html");
			String indexStatsHtml = HtmlUtils.readHtmlFile(documentsResultRowFile.getPath());
			long totalWords=0;
			long totalTime=0;
			StringBuffer sb= new StringBuffer();
			Statistics stats= model.indexPath(Constants.FOLDER_DOCUMENTS);
			for(Entry<DocumentDto,DocumentStatisticsDto> documentEntry : stats.getDocumentsStatistics().entrySet()) {
				DocumentStatisticsDto statistic = documentEntry.getValue();
				String actualDoc= indexDocumentHtml.replace("##DOC_NAME##", documentEntry.getKey().getFileName());
				actualDoc= actualDoc.replace("##DOC_WORDS##", Integer.toString(statistic.getWordsQuantity()));
				actualDoc= actualDoc.replace("##DOC_TIME##", Long.toString(statistic.getIndexTime()));
				totalTime+=statistic.getIndexTime();
				totalWords+=statistic.getWordsQuantity();
				sb.append(actualDoc);
			}
			indexStatsHtml= indexStatsHtml.replaceAll("##RBYTES##", Long.toString(stats.getReadedBytes()));
			indexStatsHtml= indexStatsHtml.replaceAll("##WBYTES##", Long.toString(stats.getWrittenBytes()));
			indexStatsHtml= indexStatsHtml.replaceAll("##WORDS##", Long.toString(totalWords));
			indexStatsHtml= indexStatsHtml.replaceAll("##TIME##", Long.toString(totalTime));
			
			indexContentHtml= indexContentHtml.replace("##DOCUMENTS_INFO##", sb.toString());
			indexContentHtml= indexContentHtml.replace("##INDEX_INFO##", indexStatsHtml);
			return indexContentHtml;
		} catch (Exception e) {
			e.printStackTrace();
		}
		return "Ocurrio un Error";
	}
	
}
