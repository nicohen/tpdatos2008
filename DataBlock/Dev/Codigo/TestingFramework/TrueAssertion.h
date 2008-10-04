#ifndef TrueAssertion_H_
#define TrueAssertion_H_

#include "Assertion.h"

class TrueAssertion:public Assertion{

private:
	char* _message;
public:
	//Constructores y destructores 	
	TrueAssertion(bool expr);
	TrueAssertion(bool expr,char* message);
	virtual ~TrueAssertion();
	virtual void printFailMessage();
	
};

#endif /*TESTCASE_H_*/

