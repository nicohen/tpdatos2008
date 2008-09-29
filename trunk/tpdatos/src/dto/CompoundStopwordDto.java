package dto;

import java.util.ArrayList;
import java.util.List;

public class CompoundStopwordDto {
	List<SingleStopwordDto> stopword = null;
	
	public CompoundStopwordDto() {
		this.stopword = new ArrayList<SingleStopwordDto>();
	}

	public List<SingleStopwordDto> getCompoundStopword() {
		return this.stopword;
	}

	public void setSingleStopword(SingleStopwordDto singleWord) {
		this.stopword.add(singleWord);
	}
		
	public int getCompoundStopwordSize() {
		return this.stopword.size();
	}
}
