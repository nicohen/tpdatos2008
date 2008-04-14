#include "RawRecord.h"
#include "../Utils.h"

RawRecord::RawRecord(char* content, T_BLOCKSIZE size){
	this->_content=(char*) malloc(size);
	memcpy(this->_content,content,size);
	this->_size=size;
}
T_BLOCKSIZE RawRecord::getSize(){
	return this->_size;
}
char* RawRecord::getContent(){
	 return this->_content;	
}

RawRecord::~RawRecord()
{
	free(this->_content);
}
