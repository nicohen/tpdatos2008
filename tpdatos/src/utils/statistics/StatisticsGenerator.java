package utils.statistics;

public class StatisticsGenerator {

	private Statistics stats;
	
	StatisticsGenerator () {
		
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
	
	public Statistics finish() {
		return stats;
	}
	
}
