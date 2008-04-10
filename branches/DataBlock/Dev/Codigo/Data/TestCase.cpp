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


void TestCase::Assert_True(bool expr){
	this->reportAssertion(new TrueAssertion(expr));
}


void TestCase::Assert_True_m(bool expr,char* msg){
	this->reportAssertion(new TrueAssertion(expr,msg));
}


void TestCase::Assert_streq(char* expected, char* actual){
	this->reportAssertion(new EqualsAssertion(expected,actual));
}

void TestCase::Assert_inteq(int expected, int actual){
	this->reportAssertion(new EqualsIntAssertion(expected,actual));
}