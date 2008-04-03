#ifndef REMOVESTATEMENT_H_
#define REMOVESTATEMENT_H_

#include "Statement.h"

class RemoveStatement : public Statement{
public:
	//Constructores y destructores 
	RemoveStatement(char* filename);
	virtual ~RemoveStatement();
	
	virtual StatementResult* execute(DataManager* anIDataManager);
	virtual void writeStatementQuery(OutPutter* outPutter);
};

#endif /*REMOVESTATEMENT_H_*/
