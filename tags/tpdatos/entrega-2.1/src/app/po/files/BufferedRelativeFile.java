package app.po.files;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.ListIterator;

import api.po.files.File;
import api.po.persistors.Persistor;
import exceptions.DataAccessException;
import exceptions.PersistanceException;

public class BufferedRelativeFile<E> implements File<E> {

	private RelativeFile<E> file;
	private ArrayList<BufferBlock<E>> buffer;
	private int bufferSize;
	private int bufferLength;
	private int bufferMark;
	
	public BufferedRelativeFile(String fileName,Persistor<E> persistor,int bufferSize) throws DataAccessException {
		super();
		this.file= new RelativeFile<E>(fileName,persistor);
		this.bufferSize=bufferSize;
		this.bufferLength=bufferSize/persistor.getDataSize();
		if (this.bufferSize<1){
			throw new DataAccessException("El tamano del buffer es mas chico que el de los elementos ("+bufferSize+"|"+persistor.getDataSize()+")");
		}
		this.bufferMark=Integer.MIN_VALUE;
		this.buffer= new ArrayList<BufferBlock<E>>();
	}

	@Override
	public int add(E element) throws DataAccessException, PersistanceException {
		int pos= this.file.add(element);
		insetIntoBuffer(pos, element, false);
		return pos;
	}

	@Override
	public void delete() {
		// TODO Auto-generated method stub
	}

	@Override
	public E get(int elementId) throws DataAccessException {
		E element= findInBuffer(elementId);
		if (element==null){
			element=this.file.get(elementId);
			insetIntoBuffer(elementId, element, false);
		}
		return element;
	}

	private void insetIntoBuffer(int elementId, E element, boolean dirty)
			throws DataAccessException {
		this.buffer.add(new BufferBlock<E>(elementId,element,this.bufferMark,dirty));
		this.bufferMark++;
		Collections.sort(this.buffer);
		if (this.buffer.size()>this.bufferLength){
			this.ajustBuffer(this.bufferLength);
		}
		if (this.bufferMark==Integer.MAX_VALUE){
			reinitMarks();
		}
	}
	
	private void reinitMarks() {
		this.bufferMark=Integer.MIN_VALUE;
		ListIterator<BufferBlock<E>> it= this.buffer.listIterator(this.buffer.size());
		while (it.hasPrevious()){
			BufferBlock<E> block=it.previous();
			block.setReplacementMark(this.bufferMark);
			this.bufferMark++;
		}
	}

	private void ajustBuffer(int bufferLength2){
		try {
			BufferBlock<E> block= this.buffer.get(this.bufferLength);
			if (block.isDirty()){
				this.file.update(block.getPosition(),block.getElement());
			}
			this.buffer.remove(this.bufferLength);
		} catch (DataAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (PersistanceException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private E findInBuffer(int position){
		Iterator<BufferBlock<E>> it= this.buffer.iterator();
		while (it.hasNext()){
			BufferBlock<E> block= it.next();
			if (block.getPosition()==position){
				block.setReplacementMark(this.bufferMark);
				this.bufferMark++;
				return block.getElement();
			}
		}
		return null;
	}
	
	@Override
	public int getSize() {
		return this.file.getSize();
	}

	@Override
	public void remove(int elementId) throws DataAccessException {
		// TODO Auto-generated method stub
		
	}

	@Override
	public int update(int elementId, E newElement) throws DataAccessException,PersistanceException {
		if (this.file.persistor.getDataSize()<this.file.persistor.getElementSize(newElement)){
			throw new PersistanceException("Error modificando elemento: "+newElement.toString());
		}
		boolean found= false;
		Iterator<BufferBlock<E>> it= this.buffer.iterator();
		while (it.hasNext()){
			BufferBlock<E> block= it.next();
			if (block.getPosition()==elementId){
				found=true;
				block.setReplacementMark(this.bufferMark);
				this.bufferMark++;
				block.setDirty();
				block.setElement(newElement);
			}
		}
		if (found==false){
			insetIntoBuffer(elementId, newElement,true);
		}
		return elementId;
	}
	
	public void close(){
		Iterator<BufferBlock<E>> it= this.buffer.iterator();
		while (it.hasNext()){
			BufferBlock<E> block= it.next();
			if (block.isDirty()){
				try {
					this.file.update(block.getPosition(),block.getElement());
				} catch (DataAccessException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} catch (PersistanceException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
		this.file.close();
	}
	
	@Override
	protected void finalize() throws Throwable {
		this.close();
		super.finalize();
	}
}

class BufferBlock<E> implements Comparable<BufferBlock<E>>{
	
	private boolean dirty;
	private int replacementMark;
	private E element;
	private int position;
	
	public BufferBlock(int position, E element,int mark, boolean dirty) {
		super();
		this.position=position;
		this.dirty= dirty;
		this.element= element;
		this.replacementMark= mark;
	}

	public boolean isDirty() {
		return dirty;
	}
	
	public void setDirty() {
		this.dirty= true;
	}
	
	public int getReplacementMark() {
		return replacementMark;
	}

	public void setReplacementMark(int replacementMark) {
		this.replacementMark = replacementMark;
	}

	public E getElement() {
		return element;
	}

	public void setElement(E element) {
		this.dirty= true;
		this.element = element;
	}

	@Override
	public int compareTo(BufferBlock<E> o) {
		return o.replacementMark-this.replacementMark;
	}

	public int getPosition() {
		return position;
	}	
}
