package dto;


public class DocumentDto {
	private Integer documentId;
	public void setDocumentId(Integer documentId) {
		this.documentId = documentId;
	}

	private String fileName;
	
	public DocumentDto(Integer documentId, String fileName) {
		this.documentId = documentId;
		this.fileName = fileName;
	}

	public DocumentDto(String fileName) {
		this.fileName = fileName;
	}
	
	public String getFileName() {
		return fileName;
	}

	public void setFileName(String document) {
		this.fileName = document;
	}
	
	public Integer getDocumentId() {
		return documentId;
	}

}