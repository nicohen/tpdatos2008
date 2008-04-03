#ifndef ENDSTATEMENT_H_
#define ENDSTATEMENT_H_

#include "Statement.h"
#include "OutPutter.h"

class EndStatement : public Statement{
public:
	//Constructores y destructores 
	EndStatement(char* filename);
	virtual ~EndStatement();
	
	virtual void execute(void* anIDataManager, OutPutter* anOutputter);
};

#endif /*ENDSTATEMENT_H_*/
