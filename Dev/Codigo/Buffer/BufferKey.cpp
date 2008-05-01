#include "BufferKey.h"
#include "../Utils.h"

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
	if (strcmp( key1->getFileName(), key2->getFileName() ) < 0){
		return true;
	}
	return (key1->getBlockNumber()<key2->getBlockNumber());
}

BufferKey::~BufferKey(){
	free(_fileName);
}
