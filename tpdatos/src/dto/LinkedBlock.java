package dto;

import java.util.ArrayList;

public class LinkedBlock<E> {
	private int nextBlock;
	private int freeRegsNum;
	private ArrayList<E> listaElem;

	
	public LinkedBlock(){
		this.nextBlock=0;
		this.freeRegsNum=-1;
		listaElem=new ArrayList<E>();
	}
	public int getNextBlock(){
		return this.nextBlock;
	}
	public int getFreeRegsNum(){
		return this.freeRegsNum;
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
	public void setFreeRegsNum(int num){
		this.freeRegsNum=num;
	}
	
}
