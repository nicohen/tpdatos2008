#include "BlocksBuffer.h"
BlocksBuffer::BlocksBuffer(int size):_systemBuffer(size){
}

BlocksBuffer::~BlocksBuffer(){
}

bool BlocksBuffer::isInBuffer(char* fileName,int blockNumber){
	BufferKey* bk= new BufferKey(fileName,blockNumber);
	bool found= this->_systemBuffer.isInBuffer(bk);
	delete bk;
	return found;
}

void BlocksBuffer::addBlock(char* fileName, int blockNumber, Block* block){
	BufferKey* bk= new BufferKey(fileName,blockNumber);
	this->_systemBuffer.addElement(bk,block);
}

Block* BlocksBuffer::getBlock(char* fileName, int blockNumber){
	BufferKey* bk= new BufferKey(fileName,blockNumber);
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

unsigned int BlocksBuffer::getCurrentSize() {
	return _systemBuffer.getCurrentSize();
}

unsigned int BlocksBuffer::getBlocksCount() {
	return _systemBuffer.getElementsCount();
}

void  BlocksBuffer::removeBlock(char* fileName, int blockNumber){
	BufferKey* bk= new BufferKey(fileName,blockNumber);
	this->_systemBuffer.removeElement(bk);
	delete bk;
}
