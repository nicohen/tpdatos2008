package dto;

import java.util.Map;
import java.util.TreeMap;

public class DocumentsReportDto {

	private Map<DocumentDto,Integer> documentOcurrences = null;
	
	public DocumentsReportDto() {
		this.documentOcurrences = new TreeMap<DocumentDto,Integer>();
	}
	
	public void setOcurrence(DocumentDto documentDto) {
		if(documentOcurrences.get(documentDto)==null) {
			documentOcurrences.put(documentDto, 1);
		} else {
			documentOcurrences.put(documentDto, documentOcurrences.get(documentDto)+1);
		}
	}
	
	public Map<DocumentDto,Integer> getOcurrences() {
		return documentOcurrences;
	}
	
	public Integer getDocumentOcurrences(DocumentDto document) {
		return documentOcurrences.get(document);
	}
}
