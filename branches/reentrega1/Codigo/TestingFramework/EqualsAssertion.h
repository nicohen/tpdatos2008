#ifndef EqualsAssertion_H_
#define EqualsAssertion_H_

#include "Assertion.h"

class EqualsAssertion:public Assertion{
private:
	char* _expected;
	char* _actual;
public:
	//Constructores y destructores 	
	EqualsAssertion(char* expected, char* actual);
	virtual ~EqualsAssertion();
	virtual void printFailMessage();
};

#endif /*EqualsAssertion*/
