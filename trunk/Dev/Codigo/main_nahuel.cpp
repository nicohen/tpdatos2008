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

#import "DataValue.h"
#import "IntValue.h"
#import "StructureValue.h"
#import "StringValue.h"

#import "Tokenizer.h"
#import "StatementParser.h"


#include <exception>
using namespace std;
using namespace Parsing;

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
	char* _message;
public:
	
	TrueAssertion(bool expr){
		if(!expr){
			reportAssertionFailed();
		}
	}
	
	TrueAssertion(bool expr,char* message){
		if(!expr){
			reportAssertionFailed();
		}
		_message=message;
	}
	
	virtual void printFailMessage(){
		if(!this->evaluate()){
			printf("Expected \"true\" but was \"false\". Msg: \"%s\"",_message);	
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
	test->reportAssertion(new EqualsAssertion("datos.dat",vvCreateStatement->getFileName()));
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
	test->reportAssertion(new EqualsAssertion("datos.dat",vvCreateStatement->getFileName()));
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

void test_DataTypesEqualsWithSimpleTypes(TestCase* test){
	DataType* vvInt1=NULL;
	DataType* vvInt2=NULL;
	DataType* vvStr1=NULL;
	DataType* vvStr2=NULL;
	vvInt1=new IntType();
	vvInt2=new IntType();
	vvStr1=new StringType();
	vvStr2=new StringType();
	test->reportAssertion(new TrueAssertion(vvInt1->equals(vvInt2)));
	test->reportAssertion(new TrueAssertion(!(vvInt1->equals(vvStr1))));
	test->reportAssertion(new TrueAssertion(!(vvStr1->equals(vvInt1))));
	test->reportAssertion(new TrueAssertion(vvStr1->equals(vvStr2)));
	delete(vvInt1);
	delete(vvInt2);
	delete(vvStr1);
	delete(vvStr2);
}

void test_DataTypesEqualsWithStructureTypes(TestCase* test){
	StructureType* vvStruct1=NULL;
	StructureType* vvStruct2=NULL;
	StructureType* vvStruct3=NULL;
	StructureType* vvStruct4=NULL;
	
	vvStruct1=new StructureType();
	vvStruct1->addType(new IntType());
	vvStruct1->addType(new IntType());
		
	vvStruct2=new StructureType();
	vvStruct2->addType(new IntType());
	vvStruct2->addType(new IntType());
	
	vvStruct3=new StructureType();
	vvStruct3->addType(new IntType());
	vvStruct3->addType(new StringType());
	
	vvStruct4=new StructureType();
	vvStruct4->addType(new IntType());
	vvStruct4->addType(new IntType());
	vvStruct4->addType(new StringType());
	
	test->reportAssertion(new TrueAssertion(vvStruct1->equals(vvStruct2)));
	test->reportAssertion(new TrueAssertion(vvStruct2->equals(vvStruct1)));
	
	test->reportAssertion(new TrueAssertion(!(vvStruct1->equals(vvStruct3))));
	test->reportAssertion(new TrueAssertion(!(vvStruct3->equals(vvStruct1))));
	
	test->reportAssertion(new TrueAssertion(!(vvStruct2->equals(vvStruct4))));
	test->reportAssertion(new TrueAssertion(!(vvStruct4->equals(vvStruct2))));
	
	vvStruct2->addType(new StringType());
	
	test->reportAssertion(new TrueAssertion((vvStruct2->equals(vvStruct4))));
	test->reportAssertion(new TrueAssertion((vvStruct4->equals(vvStruct2))));

	delete(vvStruct4);
	delete(vvStruct3);
	delete(vvStruct2);
	delete(vvStruct1);
}

void test_intValue(TestCase* test){
	IntValue* vvInt1=NULL;
	IntValue* vvInt2=NULL;
	DataType* vvIntType1=NULL;
	DataType* vvIntType2=NULL;
	vvInt1=new IntValue(10);
	vvInt2=new IntValue(15);
	
	vvIntType1=vvInt1->getType();
	vvIntType2=vvInt2->getType();
	
	
	test->reportAssertion(new TrueAssertion((vvIntType1->equals(vvIntType2))));
	
	delete(vvInt1);
	delete(vvInt2);
	delete(vvIntType1);
	delete(vvIntType2);
}

void test_StructureValue(TestCase* test){
	StructureValue* vvStructure1=0;
	StructureValue* vvStructure2=0;
	vvStructure1=new StructureValue();
	vvStructure1->addValue(new IntValue(15));
	vvStructure1->addValue(new IntValue(15));
	
	vvStructure2=new StructureValue();
	vvStructure2->addValue(new IntValue(145));
	vvStructure2->addValue(new IntValue(11));
	vvStructure2->addValue(new StringValue(""));
	
	test->reportAssertion(new TrueAssertion((vvStructure1->getType()->equals(vvStructure1->getType()))));
	
	test->reportAssertion(new TrueAssertion(!(vvStructure2->getType()->equals(vvStructure1->getType()))));
	test->reportAssertion(new TrueAssertion(!(vvStructure1->getType()->equals(vvStructure2->getType()))));
	
	vvStructure1->addValue(new  StringValue("a"));
	
	test->reportAssertion(new TrueAssertion((vvStructure2->getType()->equals(vvStructure1->getType()))));
	test->reportAssertion(new TrueAssertion((vvStructure1->getType()->equals(vvStructure2->getType()))));
	
	delete(vvStructure1);	
}

void test_TokenizerCreation(TestCase* test){
	/*FileManager::FileManager* vvFileManager = new FileManager::FileManager();
	FileManager::FileInfo *vvFileInfo;
	Tokenizer* vvTokz=NULL;		
	char SEPARATORS[]= {' ','!','\n'};
	char* KEYW[]= {"Hello","CONSULTAR"};
	vvFileInfo = vvFileManager->CreateFileInfo("In/Comandos_test.7506");
	
	vvTokz= new Tokenizer(vvFileInfo,'\'',SEPARATORS,3,KEYW ,2);
	test->reportAssertion(new TrueAssertion(0==vvTokz->getTokenReadCount()));
	vvTokz->getNextToken(false);
	test->reportAssertion(new TrueAssertion(1==vvTokz->getTokenReadCount()));
	vvFileInfo->close();
	delete(vvTokz);
	delete(vvFileInfo);
	delete(vvFileManager);*/
}

void test_ParserCreateStatementParsing(TestCase* test){
	FileManager::FileManager* vvFileManager = new FileManager::FileManager();
	FileManager::FileInfo *vvFileInfo;
	Tokenizer* vvTokz=NULL;
	StatementParser* vvStPars=NULL;
	Statement* vvFirstStatement=NULL;
	CreateStatement* vvExpectedFirstStatement=NULL;
	//char delimiters[]= {' ',';','[',']','\n'};
	char delimiters[]= {' ','[',']',';',',','\n','|'};
	char* keywords[]= {"CREAR","CONSULTAR","hash","INGRESAR","QUITAR","ELIMINAR","ESTADISTICA","FINALIZAR","ACTUALIZAR","secuencial","indexado","secIndexado"};
	vvFileInfo = vvFileManager->CreateFileInfo("In/Comandos.7506");
	vvTokz= new Tokenizer(vvFileInfo,'\'',delimiters,7,keywords ,12);	
	vvStPars=new StatementParser(vvTokz,NULL);	
	vvFirstStatement=vvStPars->getNext();
	//vvExpectedFirstStatement=dynamic_cast<CreateStatement *>(vvFirstStatement);
	vvExpectedFirstStatement=(CreateStatement *)(vvFirstStatement);
	test->reportAssertion(new TrueAssertion(NULL!=vvFirstStatement,"El statement es null"));
	test->reportAssertion(new TrueAssertion(NULL!=vvExpectedFirstStatement,"El statement no es del tipo CreateStatement"));
	test->reportAssertion(new EqualsAssertion("datos.dat",vvExpectedFirstStatement->getFileName()));
	//vvExpectedFirstStatement->getFileName()
	test->reportAssertion(new TrueAssertion(0==vvExpectedFirstStatement->getSecondaryFields()->size(),"Se esperaban 0 campos"));
	
	
	vvFileInfo->close();
	delete(vvStPars);
	delete(vvTokz);
	delete(vvFileInfo);
	delete(vvFileManager);
	
	/*FileManager::FileManager* fileManager = new FileManager::FileManager();
	FileManager::FileInfo *input;
	char SEPARATORS[]= {' ','!','\n'};
 	char* KEYW[]= {"Hello","CONSULTAR"};
 	Parsing::Tokenizer *tokenizer;
	Parsing::Token *token;

	input = fileManager->CreateFileInfo("In/Comandos.7506");
	try{
		tokenizer = new Parsing::Tokenizer(input,'\'',SEPARATORS,3,KEYW ,2);
		token = tokenizer->getNextToken(false);
		while (token!=NULL){
			printf("(%d)%s ",token->getType(),token->getContent());
			//Ya no harian falta eliminarlos
			//delete(token);
			token = tokenizer->getNextToken(false);
		}
		delete(tokenizer);
	}catch(FileManager::IOException e){}
	delete input;
	delete fileManager;*/
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
	
	
	TestCase* test6=new TestCase("test_DataTypesEqualsWithSimpleTypes",&failedTests);	
	test_DataTypesEqualsWithSimpleTypes(test6);
	delete test6;
	
	TestCase* test6bis=new TestCase("test_DataTypesEqualsWithStructureTypes",&failedTests);	
	test_DataTypesEqualsWithStructureTypes(test6bis);
	delete test6bis;
	
	TestCase* test7=new TestCase("test_intValue",&failedTests);	
	test_intValue(test7);
	delete test7;
	
	TestCase* test7bis=new TestCase("test_StructureValue",&failedTests);	
	test_StructureValue(test7bis);
	delete test7bis;
	
	TestCase* test8=new TestCase("test_TokenizerCreation",&failedTests);	
	test_TokenizerCreation(test8);
	delete test8;
	
	TestCase* test9=new TestCase("test_ParserCreateStatementParsing",&failedTests);	
	test_ParserCreateStatementParsing(test9);
	delete test9;
	
	
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




