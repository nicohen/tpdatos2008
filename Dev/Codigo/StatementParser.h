#ifndef STATEMENTPARSER_H_
#define STATEMENTPARSER_H_

#include "Tokenizer.h"
#include "Statement.h"
#include "CreateStatement.h"
#include "OutPutter.h"

class StatementParser
{
private: 
	Parsing::Tokenizer* _tokenizer;
	OutPutter* _outPutter;
	int _statementCount;
public:
	//constructores y destructores
	StatementParser(Parsing::Tokenizer* tokenizer,OutPutter* outputter);
	virtual ~StatementParser();
	
	//otros metodos
	Statement* getNext();//Devuelve el proximo Statement
};

#endif /*STATEMENTPARSER_H_*/
