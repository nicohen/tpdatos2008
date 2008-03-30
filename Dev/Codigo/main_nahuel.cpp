#import "stdio.h"
#import "string.h"
#import "stdlib.h"
#import "SecondaryIndex.h"
#import "DataType.h"
#import "IntType.h"
#import "StringType.h"
#import "CreateStatement.h"
#import "Field.h"
#import "Utils.h"

#include <exception>
using namespace std;

class Assertion{
private:
	bool _passed;
public:
	Assertion(){
		_passed=true;
	}
	
	bool evaluate(){
		return _passed;
	}
	
	virtual void printFailMessage()=0;
	
	void reportAssertionFailed(){
		this->_passed=false;
	}
	
	virtual ~Assertion(){
		
	}
};

class EqualsAssertion:public Assertion{

private:
	char* _expected;
	char* _actual;
public:
	
	EqualsAssertion(char* expected, char* actual){
		_actual=actual;
		_expected=expected;
		if(_expected==0){
			_expected="";
		}
		if(_actual==0){
			_actual="";
		}
		if(strcmp(_expected,_actual)!=0){
			this->reportAssertionFailed();
		}
	}
	
	
	virtual void printFailMessage(){
		if(!this->evaluate()){
			printf("Expected: \"%s\",But Was: \"%s\"", this->_expected, this->_actual);	
		}		
	}
	
	virtual ~EqualsAssertion(){
		
	}
};

class TrueAssertion:public Assertion{

private:
public:
	
	TrueAssertion(bool expr){
		if(!expr){
			reportAssertionFailed();
		}
	}
	
	
	virtual void printFailMessage(){
		if(!this->evaluate()){
			printf("Expected \"true\" but was \"false\"");	
		}		
	}
	
	virtual ~TrueAssertion(){
		
	}
};

class TestCase
{
public:
	bool _rest;
	char* _testName;
	int* _failedTests;
	TestCase(char* testName,int* failedTests){
		_rest=true;
		_testName=cloneStr(testName);
		_failedTests=failedTests;
		printTestStart();
	}
	
	void printTestStart(){
		printf("testing %s... \n",_testName);	
	}
	void printTestEnd(){
		if(this->_rest==true){
			printf("--->passed\n");
		}else{
			printf(">>>>FAILED\n");	
		}	
	}
	
	void reportAssertion(Assertion* assertion ){
		if( assertion->evaluate()==false){
			(*_failedTests)++;
			this->_rest=false;
			printf("    ");
			assertion->printFailMessage();
			printf("\n");
		}		
		delete(assertion);		
	}
	
	bool getResult(){
		return this->_rest;		
	}
		
	virtual ~TestCase(){
		printTestEnd();
		delete(_testName);
	}
};

void testCreation(TestCase* test){
	SecondaryIndex* vvSecondaryIndex=NULL;
	IntType* vvIntType=NULL;
	StringType* vvStringType=NULL;
	CreateStatement* vvCreateStatement=NULL;
	Field *vvField=NULL;
	vvField=new Field();
	vvField->getType();
	vvCreateStatement=new CreateStatement("Test.Test");	
	vvIntType=new IntType();
	vvStringType=new StringType();
	vvSecondaryIndex= new SecondaryIndex();
	
	delete(vvCreateStatement);	
}

void testCreateStatement(TestCase* test){
	CreateStatement* vvCreateStatement=NULL;
	vvCreateStatement=new CreateStatement("datos.dat");
	vvCreateStatement->addSecondaryField(new Field());
	test->reportAssertion(new EqualsAssertion("datos.dat",vvCreateStatement->getFileNamess()));
	delete(vvCreateStatement);
}

void testCompleteInstantiation(TestCase* test){
	CreateStatement* vvCreateStatement=NULL;
	vvCreateStatement=new CreateStatement("datos.dat");
	test->reportAssertion(new EqualsAssertion("datos.dat",vvCreateStatement->getFileNamess()));
	delete(vvCreateStatement);	
}

int main(int argc, char **argv) {
	int failedTests=0;
	
	TestCase* test1=new TestCase("testCreateStatement",&failedTests);
	testCreateStatement(test1);
	delete test1;
	TestCase* test2=new TestCase("testCreation",&failedTests);	
	testCreation(test2);
	delete test2;
	TestCase* test3=new TestCase("testCompleteInstantiation",&failedTests);	
	testCompleteInstantiation(test3);
	delete test3;
	
	if(failedTests>0){
		printf(">FAILED TESTS!!!! Count: %i\n",failedTests);
	}else{
		printf(">Tests OK\n");		
	}
		
	printf("Hola desde el main de nahuel");	
	return 0;
}




