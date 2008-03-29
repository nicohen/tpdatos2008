#ifndef STATEMENTPARSER_H_
#define STATEMENTPARSER_H_

#include "Tokenizer.h"
#include "Statement.h"
#include "CreateStatement.h"

class StatementParser
{
private: 
	Parsing::Tokenizer* _tokenizer;
	int _statementCount;
public:
	//constructores y destructores
	StatementParser(Parsing::Tokenizer* tokenizer);
	virtual ~StatementParser();
	
	//otros metodos
	Statement* getNext();//Devuelve el proximo Statement
};

#endif /*STATEMENTPARSER_H_*/
