#include "stdafx.h"
#include "TestCase.h"
#include "Common.h"

TestCase::TestCase(char* testName,int* failedTests){
	_rest=true;
	_testName=cloneStr(testName);
	_failedTests=failedTests;
	printTestStart();
}


TestCase::~TestCase(){
	printTestEnd();
	delete(_testName);
}

void TestCase::printTestStart(){
	printf("testing %s... \n",_testName);	
}

void TestCase::printTestEnd(){
	if(this->_rest==true){
		printf("--->passed\n");
	}else{
		printf(">>>>FAILED\n");	
	}	
}

void TestCase::reportAssertion(Assertion* assertion ){
	if(assertion->evaluate()==false){
		(*_failedTests)++;
		this->_rest=false;
		printf("    ");
		assertion->printFailMessage();
		printf("\n");
	}		
	delete(assertion);		
}

bool TestCase::getResult(){
	return this->_rest;		
}
