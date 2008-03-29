#include "StatementParser.h"

using namespace Parsing;
StatementParser::StatementParser(Tokenizer* tokenizer)
{
	_statementCount=0;
	_tokenizer=tokenizer;
}

Statement* StatementParser::getNext(){
	if(_statementCount>3){
		_statementCount++;
		return new CreateStatement("test.dat");
	}else{
		return 0;		
	}
}

StatementParser::~StatementParser()
{
}
