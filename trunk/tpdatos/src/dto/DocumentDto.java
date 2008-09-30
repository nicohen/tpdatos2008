package dto;


public class DocumentDto {
	private Integer offset;
	private Integer documentId;
	private String fileName;

	public DocumentDto(String fileName) {
		this.fileName = fileName;
	}
	
	public DocumentDto(Integer documentId, String fileName,Integer offset) {
		this.documentId = documentId;
		this.fileName = fileName;
		this.offset=offset;
	}
	
	public DocumentDto(Integer documentId, String fileName) {
		this.documentId = documentId;
		this.fileName = fileName;
	}
	
	public DocumentDto(Integer documentId, Integer off) {
		this.documentId = documentId;
		this.offset = off;
	}
	
	public void setDocumentId(Integer documentId) {
		this.documentId = documentId;
	}
	
	public void setOffset(Integer off) {
		this.offset = off;
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
	
	public Integer getOffset() {
		return offset;
	}

}
