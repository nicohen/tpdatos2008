#include "SystemBuffer.h"

SystemBuffer::SystemBuffer(int size){
	_bufferSize=size;
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
		/*VERIFICAR TAMAÑO*/
		Block* oldBlock;
		oldBlock= this->_buffer[bk];
		//delete oldBlock; 
		this->_buffer[bk]=block;
		return;
	}
	if ((this->_buffer.size()+/*CAMBIAR*/10)>this->_bufferSize){
		/*RESOLVER REEMPLASO*/
	}
	this->_buffer[bk]=block;
	delete bk;
}

Block* SystemBuffer::getBlock(DataFile* file, int blockNumber){
	BufferKey* bk= new BufferKey(file->getFileName(),blockNumber);
	if (this->_buffer.count(bk)>0){
		Block* oldBlock;
		oldBlock= this->_buffer[bk];
		delete bk;
		return oldBlock;
	}else{
		return NULL;
	}
}
