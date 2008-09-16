package dto;

import java.util.ArrayList;

public class LinkedBlock<E> {
	private int nextBlock;
	private ArrayList<E> listaElem;
	
	public LinkedBlock(){
		this.nextBlock=0;
		listaElem=new ArrayList<E>();
	}
	public int getNextBlock(){
		return this.nextBlock;
	}
	
	public ArrayList<E> getListaElem(){
		return this.listaElem;
	}
	
	public void setElem(E elem) {
		this.listaElem.add(elem);
	}
	
	public void setListaDocs(ArrayList<E> listaEl) {
		this.listaElem = listaEl;
	}
	public void setNextBlock(int blockId){
		this.nextBlock=blockId;
	}
	
}
