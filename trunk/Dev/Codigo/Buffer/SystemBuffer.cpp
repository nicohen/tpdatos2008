#include "SystemBuffer.h"
#include "../Utils.h"

SystemBuffer::SystemBuffer(int size){
	_bufferSize=size;
	this->_bufferCurrentSize=0;
}

SystemBuffer::~SystemBuffer(){
}
bool SystemBuffer::isInBuffer(IComparable* key){
	return (this->_buffer.count(key)>0); 
}

void SystemBuffer::addElement(IComparable* key, IBuffereable* value){
	if (this->_buffer.count(key)>0){
		this->removeElement(key);
	}
	if (this->_bufferSize<value->getSize()){
		//throw new BufferException("Tamaño de bloque mayor al del buffer");;
		DEBUG("Tamaño de bloque mayor al del buffer");
		return;
	}
	if ((this->_bufferCurrentSize+value->getSize())>this->_bufferSize){
		this->makeSpace(value->getSize());
	}
	this->_buffer[key]=value;
	this->_bufferCurrentSize+=value->getSize();
	this->replacementCriteria.setItem(key);
}

IBuffereable* SystemBuffer::getElement(IComparable* key){
	if (this->_buffer.count(key)>0){
		IBuffereable* oldBlock;
		oldBlock= this->_buffer[key];
		this->replacementCriteria.notifyHit(key);
		return oldBlock;
	}else{
		return NULL;
	}
}

void SystemBuffer::makeSpace(int elementSize){
	while ((this->_bufferCurrentSize+elementSize)>this->_bufferSize){
		IComparable* bk= (IComparable*)this->replacementCriteria.getUnusedItem();
		this->removeElement(bk);
	}	
}

void SystemBuffer::removeElement(IComparable* bk){
	IComparable* key;
	IBuffereable* value;
	map<IComparable*, IBuffereable*, bufferKeyCmp>::iterator iter = this->_buffer.find(bk);
	if( iter != this->_buffer.end() ) {
		this->replacementCriteria.notifyDelete(bk);
		key= iter->first;
		value= iter->second;
		this->_buffer.erase(bk);
		delete key;
		this->_bufferCurrentSize-=value->getSize();
		delete value;
	}
}
