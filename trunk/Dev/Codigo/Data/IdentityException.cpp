#include "IdentityException.h"

IdentityException::IdentityException(char* msg)
{
	this->_msg=msg;
}

char* IdentityException::toString(){
	return this->_msg;
}

IdentityException::~IdentityException()
{
}
