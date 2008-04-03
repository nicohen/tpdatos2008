#ifndef QUERYSTATEMENT_H_
#define QUERYSTATEMENT_H_

#include "Statement.h"

class QueryStatement : public Statement{
public:
	//Constructores y destructores 
	QueryStatement(char* filename);
	virtual ~QueryStatement();
	
	virtual StatementResult* execute(DataManager* anIDataManager);
	virtual void writeStatementQuery(OutPutter* outPutter);
};

#endif /*QUERYSTATEMENT_H_*/
