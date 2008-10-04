#ifndef STATEMENTPARSER_H_
#define STATEMENTPARSER_H_

#include "ITokenizer.h"
#include "Statement.h"
#include "CreateStatement.h"
#include "OutPutter.h"
#include "StructureType.h"
#include "StructureValue.h"
#include "Field.h"
#include "DataType.h"
#include "Token.h"
#include "StringType.h"
#include "IntType.h"
#include "KillDaemonException.h"
#include "StatementParserException.h"
#include "UpdateStatement.h"
#include "StatsStatement.h"
#include "RemoveStatement.h"
#include "QueryStatement.h"
#include "DeleteStatement.h"
#include "InsertionStatement.h"
#include <vector>
#include "IOException.h"

using namespace Parsing;
class StatementParser
{
private: 
	Parsing::ITokenizer* _tokenizer;
	OutPutter* _outPutter;
	int _statementCount;
	
	int parseFileType();
	std::vector<Field*>* parseFields();
	std::vector<DataValue*>* parseValues();
	void parseParameters(CreateStatement* statement);
	void parseIndex(CreateStatement* statement);
	StructureType* parseStructuredType();
	StructureValue* parseStructuredValue();
	Statement* parseCreateStatement();
	Statement* parseInsertionStatement();
	Statement* parseQueryStatement();
	Statement* parseRemoveStatement();
	Statement* parseDeleteStatement();
	Statement* parseStatsStatement();
	Statement* parseUpdateStatement();
	
public:
	//constructores y destructores
	StatementParser(Parsing::ITokenizer* tokenizer,OutPutter* outputter);
	virtual ~StatementParser();
	Field* parseField(Token* currentToken);
	DataType* parseType(Token* currentToken);
	//otros metodos
	Statement* getNext();//Devuelve el proximo Statement
};

#endif /*STATEMENTPARSER_H_*/
