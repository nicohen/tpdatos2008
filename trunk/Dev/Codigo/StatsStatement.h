#ifndef STATSSTATEMENT_H_
#define STATSSTATEMENT_H_

#include "Statement.h"

class StatsStatement : public Statement{
public:
	//Constructores y destructores 
	StatsStatement(char* filename);
	virtual ~StatsStatement();
	
	virtual StatementResult* execute(DataManager* anIDataManager);
	virtual void writeStatementQuery(OutPutter* outPutter);
};

#endif /*STATSSTATEMENT_H_*/
