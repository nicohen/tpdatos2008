package dto;

public class LinkedBlock<E> {
	private int nextBlock;
	private E element;
	
	@Override
	public
	boolean equals(Object obj) {
		
		LinkedBlock<E> element_e = (LinkedBlock<E>)obj; 
		
		if (element_e.getElem().equals(element) &&
			element_e.getNextBlock() == nextBlock	
			) {
			
			return true;
		} else {	
			return false;
		}
	}
	
	public LinkedBlock(){
		this.nextBlock=0;
	}
	public int getNextBlock(){
		return this.nextBlock;
	}
/*	public int getFreeRegsNum(){
		return this.freeRegsNum;
	}*/
/*	public ArrayList<E> getListaElem(){
		return this.listaElem;
	}*/
	public E getElem() {
//		this.listaElem.add(elem);
		return element;
	}
	
	public void setElem(E elem) {
//		this.listaElem.add(elem);
		this.element = elem;
	}
	
	public void setNextBlock(int blockId){
		this.nextBlock=blockId;
	}
/*	public void setFreeRegsNum(int num){
		this.freeRegsNum=num;
	}*/
	

}
