package web.search;

import java.io.File;
import java.io.IOException;
import java.util.Iterator;

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
		Iterator<DocumentDto> documentsFound;
		int size = 0;
		String html = "";
		int totalOcurrences = 0;

		try {
		
			if(!"".equals(model.getSearchWord())) {
				try {
					//documentsFound = model.searchWord(model.getSearchWord());
					documentsFound = model.iteratorQuery(model.getSearchWord());
					
					if(documentsFound!=null) {
						
						if(documentsFound.hasNext()) {
					
							drDto = new DocumentsReportDto();
							
							while (documentsFound.hasNext() ) {
								DocumentDto document = documentsFound.next();
								drDto.setOcurrence(document);
								size++;
							}
							
							File documentsResultRowFile = new File(basePath+Constants.FILE_DOCUMENT_RESULT_ROW);
							String documentsResultRowHtml = HtmlUtils.readHtmlFile(documentsResultRowFile.getPath());
							
							for(DocumentDto documentResult : drDto.getOcurrences().keySet()) {
								String otherDocumentsResultRowHtml = documentsResultRowHtml;
								int ocurrQty = drDto.getOcurrences().get(model.getEngine().getDocumentFromId(documentResult.getDocumentId()));
								totalOcurrences+=ocurrQty;
								otherDocumentsResultRowHtml = otherDocumentsResultRowHtml.replace("##TITLE##", ocurrQty+" "+((ocurrQty>1)?"ocurrencias":"ocurrencia")+" en "+documentResult.getFileName());
								otherDocumentsResultRowHtml = otherDocumentsResultRowHtml.replaceAll("##DOC_ID##", ""+documentResult.getDocumentId());
								otherDocumentsResultRowHtml = otherDocumentsResultRowHtml.replace("##IFR_SRC##", (model.getContextPath()+File.separator+Constants.FOLDER_INDEXED+File.separator+documentResult.getFileName()).replace("\\", "/"));
								strB.append(otherDocumentsResultRowHtml);				
							}
					
						}
					}
				} catch(BusinessException e) {
					e.printStackTrace();
				}
			}
			
			File documentsResultFile = new File(basePath+Constants.FILE_DOCUMENTS_RESULT);
			String documentsResultHtml = HtmlUtils.readHtmlFile(documentsResultFile.getPath());

			File file = new File(basePath+Constants.FILE_SEARCH_CONTENT);
			html = HtmlUtils.readHtmlFile(file.getPath());

			if(!"".equals(model.getSearchWord())) {
				html = html.replace("##SEARCH_WORD##", model.getSearchWord());
			} else {
				html = html.replace("##SEARCH_WORD##", "");
			}

			String resultReplacement = documentsResultHtml.replace("##RESULTADOS##", strB.toString());
			resultReplacement = resultReplacement.replace("##RES_QTY##", ""+totalOcurrences);
			if(size>0) {
				html = html.replace("##RESULTADOS##", resultReplacement);
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
				html = html.replace("##SF_SELECTED##", "checked");
			}
		} catch(IOException e) {
			e.printStackTrace();
		}

		return html;
	}


}