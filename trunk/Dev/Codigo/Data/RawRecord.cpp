#include "RawRecord.h"

RawRecord::RawRecord(char* content, T_BLOCKSIZE size){
	this->_content=content;
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
}
