#ifndef UPDATESTATEMENT_H_
#define UPDATESTATEMENT_H_

#include "Statement.h"
#include "OutPutter.h"

class UpdateStatement : public Statement{
public:
	//Constructores y destructores 
	UpdateStatement(char* filename);
	virtual ~UpdateStatement();
	
	virtual void execute(void* anIDataManager, OutPutter* anOutputter);
};

#endif /*UPDATESTATEMENT_H_*/
