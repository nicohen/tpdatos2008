#ifndef STATSSTATEMENT_H_
#define STATSSTATEMENT_H_

#include "Statement.h"
#include "OutPutter.h"

class StatsStatement : public Statement{
public:
	//Constructores y destructores 
	StatsStatement(char* filename);
	virtual ~StatsStatement();
	
	virtual void execute(void* anIDataManager, OutPutter* anOutputter);
};

#endif /*STATSSTATEMENT_H_*/
