package dto;

public class DocumentStatisticsDto {
	private int wordsQuantity;
	private long indexTime;
	
	public DocumentStatisticsDto() {
		
	}

	public void setWordsQuantity(int wordsQuantity) {
		this.wordsQuantity = wordsQuantity;
	}

	public int getWordsQuantity() {
		return wordsQuantity;
	}

	public void setIndexTime(long indexTime) {
		this.indexTime = indexTime;
	}

	public long getIndexTime() {
		return indexTime;
	}
	
	
}
