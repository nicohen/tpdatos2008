package registros;

import java.util.ArrayList;

public class LinkedBlock {
	private int nextBlock;
	ArrayList<Integer> listaDocs;
	
	public int getNextBlock(){
		return this.nextBlock;
	}
	
	public ArrayList<Integer> getListaDocs(){
		return this.listaDocs;
	}
	
	public void setNumBloque(int blockId){
		this.nextBlock=blockId;
	}
	
}
