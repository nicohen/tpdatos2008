#ifndef STATSSTATEMENT_H_
#define STATSSTATEMENT_H_

#include "Statement.h"
#include "OutPutter.h"

class ConsultStatemet : public Statement{
public:
	//Constructores y destructores 
	ConsultStatemet(char* filename);
	virtual ~ConsultStatemet();
	
	virtual void execute(void* anIDataManager, OutPutter* anOutputter);
};

#endif /*STATSSTATEMENT_H_*/
