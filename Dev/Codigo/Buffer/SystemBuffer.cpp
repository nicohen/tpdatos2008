#include "SystemBuffer.h"

SystemBuffer::SystemBuffer(int size){
	_bufferSize=size;
	this->_bufferCurrentSize=0;
}

SystemBuffer::~SystemBuffer(){
}
bool SystemBuffer::isInBuffer(DataFile* file,int blockNumber){
	BufferKey* bk= new BufferKey(file->getFileName(),blockNumber);
	bool found= (this->_buffer.count(bk)>0);
	delete bk;
	return found; 
}

void SystemBuffer::addBlock(DataFile* file, int blockNumber, Block* block){
	BufferKey* bk= new BufferKey(file->getFileName(),blockNumber);
	if (this->_buffer.count(bk)>0){
		this->removeElement(bk);
	}
	if (this->_bufferSize<block->getSize()){
		//throw new BufferException("Tamaño de bloque mayor al del buffer");;
		DEBUG("Tamaño de bloque mayor al del buffer");
		return;
	}
	if ((this->_bufferCurrentSize+block->getSize())>this->_bufferSize){
		this->makeSpace(this->_bufferSize);
	}
	this->_buffer[bk]=block;
	this->_bufferCurrentSize+=block->getSize();
	this->replacementCriteria.setItem(bk);
}

Block* SystemBuffer::getBlock(DataFile* file, int blockNumber){
	BufferKey* bk= new BufferKey(file->getFileName(),blockNumber);
	if (this->_buffer.count(bk)>0){
		Block* oldBlock;
		oldBlock= this->_buffer[bk];
		this->replacementCriteria.notifyHit(bk);
		delete bk;
		return oldBlock;
	}else{
		delete bk;
		return NULL;
	}
}

void SystemBuffer::makeSpace(int elementSize){
	while ((this->_bufferCurrentSize+elementSize)>this->_bufferSize){
		BufferKey* bk= (BufferKey*)this->replacementCriteria.getUnusedItem();
		this->removeElement(bk);
	}	
}

void SystemBuffer::removeElement(BufferKey* bk){
	BufferKey* key;
	Block* value;
	map<BufferKey*, Block*, bufferKeyCmp>::iterator iter = this->_buffer.find(bk);
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
