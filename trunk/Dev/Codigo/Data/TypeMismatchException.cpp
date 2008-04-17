#include "TypeMismatchException.h"

TypeMismatchException::TypeMismatchException(char* msg)
{
	this->_msg=msg;
}

TypeMismatchException::~TypeMismatchException()
{
}

char* TypeMismatchException::toString(){
	return this->_msg;
}
