#include "StatementParserException.h"

StatementParserException::StatementParserException(char* msg)
{
	this->_msg=msg;
}

StatementParserException::~StatementParserException()
{
}
