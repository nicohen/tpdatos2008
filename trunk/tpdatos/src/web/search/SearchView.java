package web.search;

import java.io.File;
import java.io.IOException;
import java.util.List;

import processor.utils.HtmlUtils;
import utils.Constants;
import web.View;
import dto.DocumentDto;
import dto.DocumentsReportDto;
import exceptions.BusinessException;


public class SearchView extends View {

	SearchModel model;
	
	public SearchView(SearchModel model) {
		this.model = (SearchModel)model;
	}
	
	@Override
	protected String doHtmlBody(String basePath) {
		StringBuilder strB = new StringBuilder();
		DocumentsReportDto drDto;
		List<DocumentDto> documentsFound;
		int size = 0;
		
		if(!"".equals(model.getSearchWord())) {
			try {
				documentsFound = model.searchWord(model.getSearchWord());
				
				if(documentsFound!=null) {
					size = documentsFound.size();
					if(size>0) {
				
						drDto = new DocumentsReportDto();
						
						for (DocumentDto document : documentsFound) {
							drDto.setOcurrence(document);
						}
						for(DocumentDto documentResult : drDto.getOcurrences().keySet()) {
							strB.append(drDto.getDocumentOcurrences(documentResult)+" veces en el documento "+model.getEngine().getDocumentFromId(documentResult.getDocumentId()));				
						}
				
					}
				}
			} catch(BusinessException e) {
				e.printStackTrace();
			}
		}
		
		File file = new File(basePath+Constants.FILE_SEARCH_CONTENT);

		String html = "";
		try {
			html = HtmlUtils.readHtmlFile(file.getPath());
			if(!"".equals(model.getSearchWord())) {
				html = html.replace("##SEARCH_WORD##", model.getSearchWord());
			} else {
				html = html.replace("##SEARCH_WORD##", "");
			}
			if(size>0) {
				html = html.replace("##RESULTADOS##", strB.toString());
			} else if (!"".equals(model.getSearchWord())) {
				html = html.replace("##RESULTADOS##", "No se han encontrado documentos");
			} else {
				html = html.replace("##RESULTADOS##", "");
			}
			if(Constants.MODE_INDICE_INVERTIDO.equals(model.getSearchEngine())) {
				html = html.replace("##II_SELECTED##", "checked");
				html = html.replace("##SF_SELECTED##", "");
			} else if(Constants.MODE_SIGNATURE_FILES.equals(model.getSearchEngine())) {
				html = html.replace("##II_SELECTED##", "");
				html = html.replace("##SF_SELECTED##", "checked");
			} else {
				html = html.replace("##II_SELECTED##", "");
				html = html.replace("##SF_SELECTED##", "");
			}
		} catch(IOException e) {
			e.printStackTrace();
		}

		return html;
	}


}