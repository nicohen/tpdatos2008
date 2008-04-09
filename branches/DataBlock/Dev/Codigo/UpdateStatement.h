#ifndef UPDATESTATEMENT_H_
#define UPDATESTATEMENT_H_

#include "Statement.h"
#include "OutPutter.h"

class UpdateStatement : public Statement{
public:
	//Constructores y destructores 
	UpdateStatement(char* filename);
	virtual ~UpdateStatement();
	
	virtual StatementResult* execute(DataManager* anIDataManager);
	virtual void writeStatementQuery(OutPutter* outPutter);
};

#endif /*UPDATESTATEMENT_H_*/
