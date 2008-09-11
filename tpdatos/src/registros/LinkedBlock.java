package registros;

import java.util.ArrayList;

public class LinkedBlock {
	private int currentBlock;
	private int nextBlock;
	ArrayList<Integer> listaDocs;
	
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
	
	public void setNextBlock(int blockId){
		this.nextBlock=blockId;
	}
	public void setCurrentBlock(int blockId){
		this.currentBlock=blockId;
	}
	
	
}
