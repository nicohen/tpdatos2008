#include "BufferKey.h"
#include "../Utils.h"
#include "stdio.h"

BufferKey::BufferKey(char* fileName, int block){
	_fileName= cloneStr(fileName);
	_blockNumber= block;
}

char* BufferKey::getFileName(void){
	return _fileName;
}

int BufferKey::getBlockNumber(void){
	return _blockNumber;
}

bool BufferKey::isLowerThan(IComparable* other){
	BufferKey* key1= this;
	BufferKey* key2= (BufferKey*)other;
	if (strcmp( key1->getFileName(), key2->getFileName())==0 ){
		return (key1->getBlockNumber()<key2->getBlockNumber());
	}
	return (strcmp( key1->getFileName(), key2->getFileName() ) < 0);	
}

char* BufferKey::toString() {
	char* cadena = (char*)malloc(strlen(this->_fileName)+70);
	
	sprintf(cadena,"BLOCKS BUFFER: [FileName:%s] [BlockNumber:%d]",this->_fileName,this->_blockNumber);
	return cadena;
}

BufferKey::~BufferKey(){
	free(_fileName);
}
