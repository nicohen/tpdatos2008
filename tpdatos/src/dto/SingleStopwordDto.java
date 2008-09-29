package dto;

public class SingleStopwordDto {
	private String singleWord = null;	
	private boolean match1 = false;
	private boolean match2 = false;
	private boolean match3 = false;
	private boolean match4 = false;
	private boolean match5 = false;
	
	public SingleStopwordDto(String singleWord) {
		this.singleWord = singleWord;
	}

	public String getSingleWord() {
		return singleWord;
	}

	public void setSingleWord(String singleWord) {
		this.singleWord = singleWord;
	}

	public boolean match1Word() {
		return match1;
	}

	public void setMatch1Word(boolean match1) {
		this.match1 = match1;
	}

	public boolean match2Words() {
		return match2;
	}

	public void setMatch2Words(boolean match2) {
		this.match2 = match2;
	}

	public boolean match3Words() {
		return match3;
	}

	public void setMatch3Words(boolean match3) {
		this.match3 = match3;
	}

	public boolean match4Words() {
		return match4;
	}

	public void setMatch4Words(boolean match4) {
		this.match4 = match4;
	}

	public boolean match5Words() {
		return match5;
	}

	public void setMatch5Words(boolean match5) {
		this.match5 = match5;
	}
	
}