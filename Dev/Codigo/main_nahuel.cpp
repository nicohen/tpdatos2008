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

class AssertionException: public exception
{
private:
	virtual const char* what() const throw()
	{
		return _msg;
	}
	char* _msg;
public:
	
	char* getMsg(){
		return _msg;
	}
	
	AssertionException(char* aMsg){
		_msg=cloneStr(aMsg);	
	}
  
};

void Assert_Equals_str(char* expected, char* actual,char* aFailMessage){
	char* vvActual=actual;
	char* vvExpected=expected;
	if(vvExpected==0){
		vvExpected="";
	}
	if(vvActual==0){
		vvActual="";
	}
	if(strcmp(vvExpected,vvActual)!=0){
		printf("Expected: \"%s\",But Was: \"%s\"", vvExpected, vvActual);
		throw new AssertionException(aFailMessage);
	}
}

void Assert_True(bool anExpr,char* aFailMessage){
	if(!anExpr){
		throw new AssertionException(aFailMessage);
	}
}

void (*testFunction)() = NULL;
void handleTest(void (*testFunction)(),bool* generalTests){	
	try{
		(*testFunction)();
	}catch(AssertionException* ex){
		printf("[TestFail] msg= %s \n", ex->getMsg());
		*generalTests=false;
	}
}

void testCreation(){
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

void testCreateStatement(){
	CreateStatement* vvCreateStatement=NULL;
	//int pepe=0;
	vvCreateStatement=new CreateStatement("datos.dat");
	vvCreateStatement->addSecondaryField(new Field());
	Assert_Equals_str(vvCreateStatement->getFileNamess(),"datos.dat","getFileName");
	delete(vvCreateStatement);
}

int main(int argc, char **argv) {
	bool generalTests=true;
	handleTest(&testCreation,&generalTests);
	handleTest(&testCreateStatement,&generalTests);
	
	
	if(!generalTests){
		printf("---¡¡¡¡--FAILS--!!!!--\n");
	}else{
		printf("----OK---\n");		
	}
	
	printf("Hola desde el main de nahuel");	
	return 0;
}




