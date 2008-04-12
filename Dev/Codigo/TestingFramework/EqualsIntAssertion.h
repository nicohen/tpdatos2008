#ifndef EqualsIntAssertion_H_
#define EqualsIntAssertion_H_

#include "Assertion.h"

class EqualsIntAssertion:public Assertion{
private:
	int _expected;
	int _actual;
public:
	//Constructores y destructores 	
	EqualsIntAssertion(int expected, int actual);
	virtual ~EqualsIntAssertion();
	virtual void printFailMessage();
};

#endif /*EqualsIntAssertion*/
