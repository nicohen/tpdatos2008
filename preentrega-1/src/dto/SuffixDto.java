package dto;

public class SuffixDto implements Comparable<SuffixDto> {

	private String suffix;
	
	public SuffixDto(String suffix) {
		this.suffix = suffix;
	}

	public String getSuffix() {
		return suffix;
	}
	
	public int length() {
		return suffix.length();
	}

	@Override
	public int compareTo(SuffixDto o) {
		return (new Integer(suffix.length())).compareTo((new Integer(o.getSuffix().length())))*-1;
	}

	@Override
	public boolean equals(Object obj) {
		return suffix.equals(((SuffixDto)obj).getSuffix());
	}
	
	@Override
	public String toString() {
		return suffix;
	}
}
