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
#import "StructureType.h"


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
		if(assertion->evaluate()==false){
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
	
	vvCreateStatement=new CreateStatement("Test.Test");	
	vvIntType=new IntType();
	vvStringType=new StringType();
	vvSecondaryIndex= new SecondaryIndex();
	
	delete(vvCreateStatement);	
}

void testCreateStatement_SimpleInstantiation(TestCase* test){
	CreateStatement* vvCreateStatement=NULL;
	vvCreateStatement=new CreateStatement("datos.dat");
	
	//Verifico
	test->reportAssertion(new TrueAssertion(vvCreateStatement->getSecondaryFieldCount()==0));
	test->reportAssertion(new TrueAssertion(vvCreateStatement->getSecondaryIndex()==NULL));
	test->reportAssertion(new TrueAssertion(vvCreateStatement->getIndexSize()==0));
	test->reportAssertion(new TrueAssertion(vvCreateStatement->getDataBlockSize()==0));
	test->reportAssertion(new TrueAssertion(vvCreateStatement->getFileType()==0));	
	test->reportAssertion(new EqualsAssertion("datos.dat",vvCreateStatement->getFileNamess()));
	delete(vvCreateStatement);
}

void testCreateStatement_CompleteInstantiation(TestCase* test){
	CreateStatement* vvCreateStatement=NULL;
	SecondaryIndex* vvSecondaryIndex=NULL;
	Field* vvSecondaryField=NULL;
	IntType* vvType=NULL;
	StringType* vvType2=NULL;
	StructureType* vvType3=NULL;
	
	vvCreateStatement=new CreateStatement("datos.dat");	
	vvCreateStatement->setFileType(1);
	vvCreateStatement->setDataBlockSize(30);
	vvCreateStatement->setIndexSize(55);
	
	//Creo y seteo un indice secundario
	vvSecondaryIndex=new SecondaryIndex();
	vvCreateStatement->setSecondaryIndex(vvSecondaryIndex);//Testear aparte	
	
	//Creo y agrego un campo secundario
	vvSecondaryField=new Field();
	
	vvSecondaryField->setIsMandatory(true);
	vvSecondaryField->setIsPolyvalent(true);
	
	vvType=new IntType();	
	vvType2=new StringType();	
	vvType3=new StructureType();
	
	vvCreateStatement->addSecondaryField(vvSecondaryField);	
	
	//Verifico
	test->reportAssertion(new TrueAssertion(vvCreateStatement->getSecondaryFieldCount()==1));
	test->reportAssertion(new TrueAssertion(vvCreateStatement->getSecondaryIndex()==vvSecondaryIndex));
	test->reportAssertion(new TrueAssertion(vvCreateStatement->getIndexSize()==55));
	test->reportAssertion(new TrueAssertion(vvCreateStatement->getDataBlockSize()==30));
	test->reportAssertion(new TrueAssertion(vvCreateStatement->getFileType()==1));	
	test->reportAssertion(new EqualsAssertion("datos.dat",vvCreateStatement->getFileNamess()));
	delete(vvCreateStatement);	
}

void testDataType_StructureType(TestCase* test){
	IntType* vvType=NULL;
	StringType* vvType2=NULL;
	StructureType* vvType3=NULL;
	vvType=new IntType();	
	vvType2=new StringType();	
	vvType3=new StructureType();	
	
	vvType3->addType(vvType);
	vvType3->addType(vvType2);
	
	delete(vvType3);
}

void testField_Simple(TestCase* test){
	Field* vvField=NULL;
	vvField=new Field();
	IntType* vvType=NULL;
	StringType* vvType2=NULL;
	StructureType* vvType3=NULL;
	
	test->reportAssertion(new TrueAssertion(vvField->isMandatory()==false));
	
	vvField->setIsMandatory(true);
	test->reportAssertion(new TrueAssertion(vvField->isMandatory()));
	
	test->reportAssertion(new TrueAssertion(vvField->isPolyvalent()==false));
	vvField->setIsPolyvalent(true);
	test->reportAssertion(new TrueAssertion(vvField->isPolyvalent()));
	
	vvType=new IntType();	
	vvType2=new StringType();	
	vvType3=new StructureType();	
	
	vvType3->addType(vvType);
	vvType3->addType(vvType2);
	
	test->reportAssertion(new TrueAssertion(vvField->getDataType()==NULL));
	vvField->setDataType(vvType3);
	test->reportAssertion(new TrueAssertion(vvField->getDataType()==vvType3));
	
	delete(vvField);
}

int main(int argc, char **argv) {
	int failedTests=0;
	
	TestCase* test1=new TestCase("testCreateStatement_SimpleInstantiation",&failedTests);
	testCreateStatement_SimpleInstantiation(test1);
	delete test1;
	TestCase* test2=new TestCase("testCreation",&failedTests);	
	testCreation(test2);
	delete test2;
	
	TestCase* test3=new TestCase("testCreateStatement_CompleteInstantiation",&failedTests);	
	testCreateStatement_CompleteInstantiation(test3);
	delete test3;
	
	TestCase* test4=new TestCase("testDataType_StructureType",&failedTests);	
	testDataType_StructureType(test4);
	delete test4;
	
	TestCase* test5=new TestCase("testField_Simple",&failedTests);	
	testField_Simple(test5);
	delete test5;
	
	
	
	printf(":::Tests:::.......................\n");
	if(failedTests>0){
		printf("!!!!!!FAILED %i TEST/S !!!!!!!!!!\n",failedTests);
	}else{
		printf("Ok\n");		
	}
	printf("..................................\n");
		
	printf("Hola desde el main de nahuel");	
	return 0;
}




