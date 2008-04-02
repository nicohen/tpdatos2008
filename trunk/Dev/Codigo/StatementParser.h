#ifndef STATEMENTPARSER_H_
#define STATEMENTPARSER_H_

#include "ITokenizer.h"
#include "Statement.h"
#include "CreateStatement.h"
#include "OutPutter.h"
#include "StructureType.h"
#include "Field.h"
#include <vector>

class StatementParser
{
private: 
	Parsing::ITokenizer* _tokenizer;
	OutPutter* _outPutter;
	int _statementCount;
	
	int parseFileType();
	vector<Field*>* parseFields();
	StructureType* parseDataType();
	Statement* parseCreateStatemet();
	Statement* parseAddStatemet();
	Statement* parseConsultStatemet();
	Statement* parseRemoveStatemet();
	Statement* parseDeleteStatemet();
	Statement* parseStatsStatemet();
	Statement* parseEndStatemet();
	Statement* parseActualizeStatemet();
public:
	//constructores y destructores
	StatementParser(Parsing::ITokenizer* tokenizer,OutPutter* outputter);
	virtual ~StatementParser();
	
	//otros metodos
	Statement* getNext();//Devuelve el proximo Statement
};

#endif /*STATEMENTPARSER_H_*/
