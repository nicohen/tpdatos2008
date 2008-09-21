package dto;


public class DocumentDto {
	private Integer documentId;
	private String fileName;
//	private List<WordDto> words = null;
	
	public DocumentDto(Integer documentId, String fileName) {
		this.documentId = documentId;
		this.fileName = fileName;
//		this.words = new ArrayList<WordDto>();
	}
	
//	public List<WordDto> getWords() {
//		return words;
//	}
//
//	public void addWord(WordDto word) {
//		this.words.add(word);
//	}

	public String getFileName() {
		return fileName;
	}

	public void setFileName(String document) {
		this.fileName = document;
	}
	
//	@Override
//	public String toString() {
//		StringBuffer sb = new StringBuffer();
//		for (WordDto dto : words) {
//			sb.append(dto.toString());
//		}
//		return sb.toString();
//	}

	public Integer getDocumentId() {
		return documentId;
	}

}
