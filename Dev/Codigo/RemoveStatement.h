#ifndef REMOVESTATEMENT_H_
#define REMOVESTATEMENT_H_

#include "Statement.h"
#include "OutPutter.h"

class RemoveStatement : public Statement{
public:
	//Constructores y destructores 
	RemoveStatement(char* filename);
	virtual ~RemoveStatement();
	
	virtual void execute(void* anIDataManager, OutPutter* anOutputter);
};

#endif /*REMOVESTATEMENT_H_*/
