#include "SystemBuffer.h"
#include "../Utils.h"

SystemBuffer::SystemBuffer(int size){
	_bufferSize=size;
	_hits = 0;
	_miss = 0;
	this->_bufferCurrentSize=0;
}

SystemBuffer::~SystemBuffer(){
}

bool SystemBuffer::isInBuffer(IComparable* key){
	if (this->_buffer.count(key)>0) {
		this->_hits++;
		return true;
	} else {
		this->_miss++;
		return false;
	}
}

void SystemBuffer::addElement(IComparable* key, IBuffereable* value){
	if (this->_buffer.count(key)>0){
		return;
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

unsigned int SystemBuffer::getCurrentSize() {
//	unsigned int totalSize = 0;
//	
//	for (map<IComparable*, IBuffereable*, bufferKeyCmp>::iterator iter = this->_buffer.begin(); iter!=this->_buffer.end(); iter++) {
//		totalSize += ((*iter).second)->getSize();
//	}
//	
	return _bufferCurrentSize/*totalSize*/;
}

unsigned int SystemBuffer::getTotalSize() {
	return _bufferSize;
}

unsigned int SystemBuffer::getHits() {
	return this->_hits;
}

unsigned int SystemBuffer::getMiss() { 
	return this->_miss;
}

unsigned int SystemBuffer::getElementsCount() {
	return _buffer.size();;
}
