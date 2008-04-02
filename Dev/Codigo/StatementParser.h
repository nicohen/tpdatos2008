#ifndef STATEMENTPARSER_H_
#define STATEMENTPARSER_H_

#include "ITokenizer.h"
#include "Statement.h"
#include "CreateStatement.h"
#include "OutPutter.h"
#include "StructureType.h"
#include "Field.h"
#include "DataType.h"
#include <vector>

class StatementParser
{
private: 
	Parsing::ITokenizer* _tokenizer;
	OutPutter* _outPutter;
	int _statementCount;
	
	int parseFileType();
	void parseFields(CreateStatement* statement);
	StructureType* parseDataType();
	Statement* parseCreateStatemet();
	Statement* parseAddStatemet();
	Statement* parseConsultStatemet();
	Statement* parseRemoveStatemet();
	Statement* parseDeleteStatemet();
	Statement* parseStatsStatemet();
	Statement* parseEndStatemet();
	Statement* parseActualizeStatemet();
	
	/*Field* parseField(Token* currentToken);*/
	/*DataType* parseType(Token* currentToken);*/
public:
	//constructores y destructores
	StatementParser(Parsing::ITokenizer* tokenizer,OutPutter* outputter);
	virtual ~StatementParser();
	
	//otros metodos
	Statement* getNext();//Devuelve el proximo Statement
};

#endif /*STATEMENTPARSER_H_*/
