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

class MyException: public exception
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
	
	MyException(char* aMsg){
		_msg=cloneStr(aMsg);	
	}
  
};

void Assert_Equals_str(char* expected, char* actual,char* aFailMessage){
	if(strcmp(expected,actual)!=0){
		printf("Expected: \"%s\",But Was: \"%s\"", expected, actual);
		throw new MyException(aFailMessage);
	}
}

void Assert_True(bool anExpr,char* aFailMessage){
	if(!anExpr){
		throw new MyException(aFailMessage);
	}
}

void (*testFunction)() = NULL;
void handleTest(void (*testFunction)(),bool* generalTests){	
	try{
		(*testFunction)();
	}catch(MyException* ex){
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
	vvCreateStatement=new CreateStatement();	
	vvIntType=new IntType();
	vvStringType=new StringType();
	vvSecondaryIndex= new SecondaryIndex();
}

void testCreateStatement(){
	CreateStatement* vvCreateStatement=NULL;
	vvCreateStatement=new CreateStatement();
	vvCreateStatement->setFileName("datos.dat");
	//Assert_True(strcmp(vvCreateStatement->getFileName(),"datos.dat"),"getFileName");
	//Assert_Equals_str(vvCreateStatement->getFileName(),"datos.dat","getFileName");
	Assert_Equals_str("datos.dats","datos.dat","getFileName");
}



int main(int argc, char **argv) {
	bool generalTests=true;
	handleTest(&testCreation,&generalTests);
	handleTest(&testCreateStatement,&generalTests);
	printf("%i",strcmp("datos.dat","datos.dat"));
	
	if(!generalTests){
		printf("---¡¡¡¡--FAILS--!!!!--\n");
	}else{
		printf("----OK---\n");		
	}
	
	printf("Hola desde el main de nahuel");	
	return 0;
}




