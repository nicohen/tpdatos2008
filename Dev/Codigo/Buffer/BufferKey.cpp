#include "BufferKey.h"
#include "../Utils.h"
#include <string>
#include <sstream>

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

char* BufferKey::toString(){
	/*string str;
	ostringstream ss;
	str.append(this->_fileName);
	str.append(" ");
	ss<<this->_blockNumber;
	str.append(ss.str());
	return str.c_str();*/
	return "";
}

BufferKey::~BufferKey(){
	free(_fileName);
}
