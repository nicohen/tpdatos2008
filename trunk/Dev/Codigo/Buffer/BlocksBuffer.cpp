#include "BlocksBuffer.h"
BlocksBuffer::BlocksBuffer(int size):_systemBuffer(size){
}

BlocksBuffer::~BlocksBuffer(){
}

bool BlocksBuffer::isInBuffer(DataFile* file,int blockNumber){
	BufferKey* bk= new BufferKey(file->getFileName(),blockNumber);
	bool found= this->_systemBuffer.isInBuffer(bk);
	delete bk;
	return found;
}

void BlocksBuffer::addBlock(DataFile* file, int blockNumber, Block* block){
	BufferKey* bk= new BufferKey(file->getFileName(),blockNumber);
	this->_systemBuffer.addElement(bk,block);
}

Block* BlocksBuffer::getBlock(DataFile* file, int blockNumber){
	BufferKey* bk= new BufferKey(file->getFileName(),blockNumber);
	IBuffereable* element=	this->_systemBuffer.getElement(bk);
	delete bk;
	return (Block*)element; 
}

unsigned int BlocksBuffer::getHits() {
	return _systemBuffer.getHits();
}

unsigned int BlocksBuffer::getMiss() {
	return _systemBuffer.getMiss();
}

unsigned int BlocksBuffer::getTotalSize() {
	return _systemBuffer.getTotalSize();
}
