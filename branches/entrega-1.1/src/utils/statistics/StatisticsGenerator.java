package utils.statistics;

import dto.DocumentDto;
import dto.DocumentStatisticsDto;

public class StatisticsGenerator {

	private Statistics stats;
	
	StatisticsGenerator () {
		init();
	}
	
	public void init() {
		stats = new Statistics();
	}
	
	public void addWrittenBytes(long bytes) {
		stats.addWrittenBytes(bytes);
	}
	
	public void addReadedBytes(long bytes) {
		stats.addReadedBytes(bytes);
	}
	
	public void addDocumentStatistics(DocumentDto document, int wordsQuantity, long indexTime) {
		DocumentStatisticsDto dsDto = new DocumentStatisticsDto();
		dsDto.setWordsQuantity(wordsQuantity);
		dsDto.setIndexTime(indexTime);
		stats.addDocumentStatistic(document, dsDto);
	}
	
	public Statistics finish() {
		return stats;
	}
	
}
