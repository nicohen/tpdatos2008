#ifndef ENDSTATEMENT_H_
#define ENDSTATEMENT_H_

#include "Statement.h"
#include "OutPutter.h"

class EndStatement : public Statement{
public:
	//Constructores y destructores 
	EndStatement(char* filename);
	virtual ~EndStatement();
	
	virtual StatementResult* execute(DataManager* anIDataManager);
	virtual void writeStatementQuery(OutPutter* outPutter);
};

#endif /*ENDSTATEMENT_H_*/
