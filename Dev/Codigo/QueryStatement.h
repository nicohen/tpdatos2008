#ifndef QUERYSTATEMENT_H_
#define QUERYSTATEMENT_H_

#include "Statement.h"
#include "OutPutter.h"

class QueryStatemet : public Statement{
public:
	//Constructores y destructores 
	QueryStatemet(char* filename);
	virtual ~QueryStatemet();
	
	virtual void execute(void* anIDataManager, OutPutter* anOutputter);
};

#endif /*QUERYSTATEMENT_H_*/
