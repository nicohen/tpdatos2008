#ifndef DELETESTATEMENT_H_
#define DELETESTATEMENT_H_

#include "Statement.h"
#include "OutPutter.h"

class DeleteStatement : public Statement{
public:
	//Constructores y destructores 
	DeleteStatement(char* filename);
	virtual ~DeleteStatement();
	
	virtual void execute(void* anIDataManager, OutPutter* anOutputter);
};

#endif /*DELETESTATEMENT_H_*/
