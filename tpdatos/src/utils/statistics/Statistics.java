package utils.statistics;

public class Statistics {
	private long writtenBytes;
	private long readedBytes;
	
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
	
	
}
