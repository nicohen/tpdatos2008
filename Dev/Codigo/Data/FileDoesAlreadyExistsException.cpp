#include "FileDoesAlreadyExistsException.h"

FileDoesAlreadyExistsException::FileDoesAlreadyExistsException(char* msg)
{
	this->_msg=msg;
}

char* FileDoesAlreadyExistsException::toString(){
	return this->_msg;
}

FileDoesAlreadyExistsException::~FileDoesAlreadyExistsException()
{
}
