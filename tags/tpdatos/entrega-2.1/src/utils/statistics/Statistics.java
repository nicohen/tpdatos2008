package utils.statistics;

import java.util.LinkedHashMap;
import java.util.Map;

import dto.DocumentDto;
import dto.DocumentStatisticsDto;

public class Statistics {
	
	private long writtenBytes;
	private long readedBytes;
	private Map<DocumentDto,DocumentStatisticsDto> documentsStatistics = null;
	
	public Statistics() {
		writtenBytes = readedBytes = 0;
		documentsStatistics = new LinkedHashMap<DocumentDto,DocumentStatisticsDto>();
	}
	
	public long getReadedBytes() {
		return readedBytes;
	}
	public long getWrittenBytes() {
		return writtenBytes;
	}
	public void addReadedBytes(long readedBytes) {
		this.readedBytes += readedBytes;
	}
	public void addWrittenBytes(long writtenBytes) {
		this.writtenBytes += writtenBytes;
	}
	
	public void addDocumentStatistic(DocumentDto document,DocumentStatisticsDto documentStatistic) {
		this.documentsStatistics.put(document, documentStatistic);
	}
	
	public Map<DocumentDto,DocumentStatisticsDto> getDocumentsStatistics() {
		return this.documentsStatistics;
	}
}
