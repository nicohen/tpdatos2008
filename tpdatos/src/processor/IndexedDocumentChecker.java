package processor;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class IndexedDocumentChecker {
	
	private Map<Integer,String> documentsMap;
	
	public IndexedDocumentChecker() {
		this.documentsMap= new HashMap<Integer, String>();
	}
	
	public void addDocument( Integer id, String str ) {
		documentsMap.put(id,str);
	}
	
	public boolean documentIsIndexed( String str ) {
		return documentsMap.containsValue(str);
	}
	
	public Integer getNewDocumentId(){ 
		Set<Integer> newDocuments = documentsMap.keySet();
		Integer maxDocumentId = 0;
		for(Integer document : newDocuments) {
			if(document>maxDocumentId) {
				maxDocumentId = document;
			}
		}
		return (newDocuments.size()>0) ? maxDocumentId+1 : 0;
	
	}
}
