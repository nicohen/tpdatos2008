#include "FileNotFoundException.h"

FileNotFoundException::FileNotFoundException(char* msg)
{
	this->_msg=msg;
}

char* FileNotFoundException::toString(){
	return this->_msg;
}

FileNotFoundException::~FileNotFoundException()
{
}
