#ifndef TESTCASE_H_
#define TESTCASE_H_

#include "Assertion.h"
#include "TrueAssertion.h"
#include "EqualsAssertion.h"

class TestCase{
private:
	bool _rest;
	char* _testName;
	int* _failedTests;
public:
	//Constructores y destructores 	
	TestCase(char* testName,int* failedTests);
	virtual ~TestCase();
	
	//Asserts
	void Assert_True(bool expr);

	void printTestStart();
	void printTestEnd();	
	void reportAssertion(Assertion* assertion );	
	bool getResult();		
};

#endif /*TESTCASE_H_*/
