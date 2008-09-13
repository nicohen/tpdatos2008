package dto;

import java.util.ArrayList;

public class LinkedBlock {
	private int currentBlock;
	private int nextBlock;
	private ArrayList<Integer> listaDocs;
	
	public LinkedBlock(){
		this.currentBlock=0;
		this.nextBlock=0;
		listaDocs=new ArrayList<Integer>();
	}
	public int getNextBlock(){
		return this.nextBlock;
	}
	public int getCurrentBlock(){
		return this.currentBlock;
	}
	
	public ArrayList<Integer> getListaDocs(){
		return this.listaDocs;
	}
	
	public void setDoc(Integer doc) {
		this.listaDocs.add(doc);
	}
	
	public void setListaDocs(ArrayList<Integer> listaDocs) {
		this.listaDocs = listaDocs;
	}
	public void setNextBlock(int blockId){
		this.nextBlock=blockId;
	}
	public void setCurrentBlock(int blockId){
		this.currentBlock=blockId;
	}
	
	
}
