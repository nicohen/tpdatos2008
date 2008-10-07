package dto;


public class DocumentDto implements Comparable<DocumentDto> {
	private Integer offset;
	private Integer documentId;
	private String fileName;
	private Integer fileNameLength;
	public DocumentDto(String fileName) {
		this.fileName = fileName;
		this.fileNameLength=fileName.length();
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
	
	public DocumentDto(Integer off,Integer length) {
		this.offset = off;
		this.fileNameLength=length;
		
	}
	
	public void setDocumentId(Integer documentId) {
		this.documentId = documentId;
	}
	
	public void setFileNameLength(Integer length) {
		this.fileNameLength = length;
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
	
	public Integer getFileNameLength() {
		return fileNameLength;
	}
	
	public Integer getOffset() {
		return offset;
	}
	
	@Override
	public String toString() {
		return fileName;
	}

	@Override
	public int compareTo(DocumentDto arg0) {
		return fileName.compareTo(arg0.getFileName());
	}

}
