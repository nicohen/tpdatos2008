#include "BufferKey.h"
#include "string.h"
#include <sstream>
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

char* BufferKey::toString() {
//	string buffer;
//	ostringstream ss;
//	buffer.append("[FileName:");
//	buffer.append(this->_fileName);
//	buffer.append("] [BlockNumber:");
//	ss<<this->_blockNumber;
//	buffer.append("]");
//	buffer.append(ss.str());
	return "";
}

BufferKey::~BufferKey(){
	free(_fileName);
}
