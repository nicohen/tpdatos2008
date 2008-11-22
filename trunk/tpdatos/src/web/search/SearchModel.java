package web.search;

public class SearchModel {

	private String searchWord;
	
	public SearchModel(String word) {
		this.searchWord = word;
	}

	public String getSearchWord() {
		return searchWord==null?"":searchWord;
	}

	public void setSearchWord(String word) {
		this.searchWord = word;
	}
	
	
}
