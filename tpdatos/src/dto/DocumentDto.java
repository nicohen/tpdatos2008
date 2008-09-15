package dto;

import java.util.ArrayList;
import java.util.List;

public class DocumentDto {
	private String document;
	private List<LineDto> pipelines = null;
	
	public DocumentDto() {
		this.pipelines = new ArrayList<LineDto>();
	}
	
	public List<LineDto> getPipelines() {
		return pipelines;
	}

	public void addPipeline(LineDto pipeline) {
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
		for (LineDto dto : pipelines) {
			sb.append(dto.getWordsPipeline().toString());
		}
		return sb.toString();
	}

}
