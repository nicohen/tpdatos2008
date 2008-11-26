package utils.statistics;

import java.util.Map.Entry;

import dto.DocumentDto;
import dto.DocumentStatisticsDto;

public class StatisticsGenerator {

	private Statistics stats;
	private static StatisticsGenerator sGenerator = null;

	private StatisticsGenerator () {
		super();
		init();
	}
	
	public static StatisticsGenerator getInstance() {
		if (sGenerator == null) {
			sGenerator = new StatisticsGenerator();
		}
		return sGenerator;
	}
	
	private void init() {
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
	
	public Statistics getStatistics() {
		return stats;
	}
	
	public static void reset(){
		sGenerator= new StatisticsGenerator();
	}
	
	@Override
	public String toString() {
		long totalWords=0;
		long totalTime=0;
		StringBuilder strB = new StringBuilder();
		strB.append("\n");
		strB.append("Documentos").append("\n");
		strB.append("----------").append("\n");
		for(Entry<DocumentDto,DocumentStatisticsDto> documentEntry : stats.getDocumentsStatistics().entrySet()) {
			DocumentStatisticsDto statistic = documentEntry.getValue();
			strB.append("[DOCUMENT: ").append(documentEntry.getKey().getFileName()).append(", WORDS: ").append(statistic.getWordsQuantity()).append(", INDEX TIME: ").append(statistic.getIndexTime()).append(" mseg.]\n");
			totalTime+=statistic.getIndexTime();
			totalWords+=statistic.getWordsQuantity();
		}
		strB.append("\n");
		strB.append("Estadisticas generales").append("\n");
		strB.append("----------------------").append("\n");
		strB.append("Cantidad total de Bytes leidos............ ").append(stats.getReadedBytes()).append(" bytes\n");
		strB.append("Cantidad total de Bytes escritos.......... ").append(stats.getWrittenBytes()).append(" bytes\n");
		strB.append("Cantidad total de terminos................ ").append(totalWords).append("\n");
		strB.append("Cantidad total de tiempo de indexacion.... ").append(totalTime).append(" mseg.");
		
		return strB.toString(); 
	}
}
