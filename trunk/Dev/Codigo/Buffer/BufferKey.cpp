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

BufferKey::~BufferKey(){
	free(_fileName);
}
