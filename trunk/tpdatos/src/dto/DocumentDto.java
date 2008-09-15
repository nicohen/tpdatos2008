package dto;

import java.util.ArrayList;
import java.util.List;

public class DocumentDto {
	private String document;
	private List<WordDto> pipelines = null;
	
	public DocumentDto() {
		this.pipelines = new ArrayList<WordDto>();
	}
	
	public List<WordDto> getPipelines() {
		return pipelines;
	}

	public void addPipeline(WordDto pipeline) {
		this.pipelines.add(pipeline);
	}

	public String getDocument() {
		return document;
	}

	public void setDocument(String document) {
		this.document = document;
	}
	
	@Override
	public String toString() {
		StringBuffer sb = new StringBuffer();
		for (WordDto dto : pipelines) {
			sb.append(dto.toString());
		}
		return sb.toString();
	}

}
