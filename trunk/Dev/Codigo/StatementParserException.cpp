#include "StatementParserException.h"

StatementParserException::StatementParserException(const char* msg){
	this->_msg=msg;
}

StatementParserException::~StatementParserException()
{
}
