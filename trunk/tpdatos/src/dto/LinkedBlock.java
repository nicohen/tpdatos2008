package dto;

import java.util.ArrayList;

public class LinkedBlock<E> {
	private int currentBlock;
	private int nextBlock;
	private ArrayList<E> listaElem;
	
	public LinkedBlock(){
		this.currentBlock=0;
		this.nextBlock=0;
		listaElem=new ArrayList<E>();
	}
	public int getNextBlock(){
		return this.nextBlock;
	}
	public int getCurrentBlock(){
		return this.currentBlock;
	}
	
	public ArrayList<E> getListaElem(){
		return this.listaElem;
	}
	
	public void setDoc(E elem) {
		this.listaElem.add(elem);
	}
	
	public void setListaDocs(ArrayList<E> listaEl) {
		this.listaElem = listaEl;
	}
	public void setNextBlock(int blockId){
		this.nextBlock=blockId;
	}
	public void setCurrentBlock(int blockId){
		this.currentBlock=blockId;
	}
	
	
}
