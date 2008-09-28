package dto;

public class LinkedBlockB<E> {
	private int nextBlock;
//	private int freeRegsNum;
//	private ArrayList<E> listaElem;
	private E element;
	
	@Override
	public
	boolean equals(Object obj) {
		
		LinkedBlockB<E> element_e = (LinkedBlockB<E>)obj; 
		
		if (element_e.getElem().equals(element) &&
			element_e.getNextBlock() == nextBlock	
			) {
			
			return true;
		} else {	
			return false;
		}
	}
	
	public LinkedBlockB(){
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
