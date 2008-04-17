#include "BlockStructuredFileException.h"
#include "../Utils.h"

BlockStructuredFileException::BlockStructuredFileException(char* message)
{
	this->_message=cloneStr(message);
}

BlockStructuredFileException::~BlockStructuredFileException()
{
	free(this->_message);
}
