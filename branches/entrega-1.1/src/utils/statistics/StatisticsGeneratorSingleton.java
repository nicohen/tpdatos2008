package utils.statistics;

public class StatisticsGeneratorSingleton {
	private static StatisticsGenerator sGenerator = null;
	
	public static StatisticsGenerator get() {
		if (sGenerator == null) {
			sGenerator = new StatisticsGenerator();
		}
		return sGenerator;
	}
	
}
